using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;

namespace rommaker
{
    class Program
    {
        static readonly string spriteRomPath = @"C:\repos\Aznable\gfx\sprite.bin";
        static readonly string palettePath = @"C:\repos\Aznable\gfx\palette.bin";

        static readonly string musicPath = @"C:\repos\Aznable\music\";
        static readonly string musicTrackListPath = @"C:\repos\Aznable\music\tracks.txt";
        static readonly string musicRomPath = @"C:\repos\Aznable\music\music.bin";
        static readonly string musicSourcePath = @"C:\repos\Aznable\src\music_tracks";

        static readonly string soundPath = @"C:\repos\Aznable\sound\";
        static readonly string soundListPath = @"C:\repos\Aznable\sound\samples.txt";
        static readonly string soundRomPath = @"C:\repos\Aznable\sound\sound.bin";
        static readonly string soundSourcePath = @"C:\repos\Aznable\src\sound_samples";

        static readonly int PaletteMax = 4;
        static readonly int PaletteIndexMax = 32;

        static readonly List<List<Color>> Palettes = new();

        static void CreateMusicRom()
        {
            if (File.Exists(musicRomPath)) { File.Delete(musicRomPath); }

            // Read track list
            string[] tracks = File.ReadAllLines(musicTrackListPath);

            List<byte> trackData = new List<byte>();
            string[] trackPos = new string[tracks.Length];

            int t = 0;
            uint p = 0;
            foreach (string track in tracks)
            {
                string file = track.Split("#")[0];
                byte[] data = File.ReadAllBytes(musicPath + file);
                trackData.AddRange(data);
                trackPos[t] = p + "u";
                p += (uint)data.Length;
                t++;
            }

            StringBuilder builder = new StringBuilder();
            builder.AppendLine("#ifndef MUSIC_TRACKS_H");
            builder.AppendLine("#define MUSIC_TRACKS_H");
            builder.AppendLine("#define const_music_track_max 32");
            builder.AppendLine("extern unsigned long music_track_address[const_music_track_max];");

            builder.AppendLine("#endif");
            File.WriteAllText(musicSourcePath + ".h", builder.ToString());

            builder = new StringBuilder();
            builder.AppendLine("#ifndef MUSIC_TRACKS_C");
            builder.AppendLine("#define MUSIC_TRACKS_C");
            builder.AppendLine("#include \"music_tracks.h\"");
            builder.AppendLine("unsigned long music_track_address[] = {" + string.Join(",", trackPos) + "};");
            builder.AppendLine("#endif");
            File.WriteAllText(musicSourcePath + ".c", builder.ToString());

            File.WriteAllBytes(musicRomPath, trackData.ToArray());

        }


        static void CreateSoundRom()
        {
            if (File.Exists(soundRomPath)) { File.Delete(soundRomPath); }

            // Read sample list
            string[] samples = File.ReadAllLines(soundListPath);

            List<byte> soundData = new List<byte>();
            string[] soundPos = new string[samples.Length];
            string[] soundLen = new string[samples.Length];
            string command = $@"C:\Program Files (x86)\sox-14-4-2\sox.exe";
            int t = 0;
            uint p = 0;

            StringBuilder builder = new StringBuilder();
            builder.AppendLine("#ifndef SOUND_SAMPLES_H");
            builder.AppendLine("#define SOUND_SAMPLES_H");
            builder.AppendLine("#define const_sound_sample_max 32");
            builder.AppendLine("extern unsigned long sound_sample_address[const_sound_sample_max];");
            builder.AppendLine("extern unsigned long sound_sample_length[const_sound_sample_max];");

            foreach (string sample in samples)
            {
                string file = sample.Split("#")[0];
                string name = sample.Split("#")[1];

                string args = $"{soundPath}{file}.wav {soundPath}{file}.vox rate 8k";
                Process.Start(command,args).WaitForExit();
                byte[] data = File.ReadAllBytes($"{soundPath}{file}.vox");
                soundData.AddRange(data);
                soundPos[t] = p + "u";
                uint l = (uint)data.Length;
                soundLen[t] = l + "u";
                builder.AppendLine($"#define const_sound_{name} {t}");
                p += l;
                t++;
            }
            

            builder.AppendLine("#endif");
            File.WriteAllText(soundSourcePath + ".h", builder.ToString());

            builder = new StringBuilder();
            builder.AppendLine("#ifndef SOUND_SAMPLES_C");
            builder.AppendLine("#define SOUND_SAMPLES_C");
            builder.AppendLine("#include \"sound_samples.h\"");
            builder.AppendLine("unsigned long sound_sample_address[] = {" + string.Join(",", soundPos) + "};");
            builder.AppendLine("unsigned long sound_sample_length[] = {" + string.Join(",", soundLen) + "};");
            builder.AppendLine("#endif");
            File.WriteAllText(soundSourcePath + ".c", builder.ToString());

            File.WriteAllBytes(soundRomPath, soundData.ToArray());

        }

        static void CreateSpriteRom()
        {

            for (int p = 0; p < PaletteMax; p++)
            {
                Palettes.Add(new List<Color>());
                Palettes[p].Add(Color.FromArgb(0, 0, 0, 0));
            }

            if (File.Exists(spriteRomPath)) { File.Delete(spriteRomPath); }
            if (File.Exists(palettePath)) { File.Delete(palettePath); }


            FileStream spriteStream = File.OpenWrite(spriteRomPath);

            uint pos = 0;

            foreach (string image in Directory.GetFiles(@"C:\repos\Aznable\gfx\images\", "*.png", SearchOption.TopDirectoryOnly))
            {
                Bitmap img = new(image);

                int slicesX = 1;
                int slicesY = 1;

                // Remove extension
                string name = image.Substring(0, image.Length - 4);

                // Detect palette
                if (!name.Contains("#"))
                {
                    throw new Exception("No palette data");
                }
                string[] paletteParts = name.Split("#");
                name = paletteParts[0];
                int paletteIndex = int.Parse(paletteParts[1]) -1;

                // Detect slices
                if (!name.Contains("-"))
                {
                    throw new Exception("No slicing data");
                }
                string end = name.Split("-")[1];
                string[] parts = end.Split("_");
                slicesX = int.Parse(parts[0]);
                slicesY = int.Parse(parts[1]);
                int sizeX = img.Width / slicesX;
                int sizeY = img.Height / slicesY;


                for (int ys = 0; ys < slicesY; ys++)
                {
                    for (int xs = 0; xs < slicesX; xs++)
                    {
                        Console.WriteLine($"Starting image: {image} - {xs},{ys} --> {pos}");
                        int ymin = ys * sizeY;
                        int ymax = ymin + sizeY;
                        int xmin = xs * sizeX;
                        int xmax = xmin + sizeX;
                        for (int y = ymin; y < ymax; y++)
                        {
                            for (int x = xmin; x < xmax; x++)
                            {

                                Color c = img.GetPixel(x, y);
                                // Find colour in palette
                                int pi = -1;
                                for (int ci = 0; ci < Palettes[paletteIndex].Count; ci++)
                                {
                                    if (Palettes[paletteIndex][ci] == c)
                                    {
                                        pi = ci;
                                    }
                                }
                                // Colour not found, add to paletta
                                if (pi == -1)
                                {
                                    pi = Palettes[paletteIndex].Count;
                                    if (pi == PaletteIndexMax)
                                    {
                                        //   throw new Exception("too many colours");
                                      
                                       Console.WriteLine($"Palette full: {image} - {xs},{ys} - {pi}, {c}");
                                        pi = 0;
                                    }
                                    else
                                    {
                                        Palettes[paletteIndex].Add(c);
                                       // Console.WriteLine($"Adding to palette: {image} - {xs},{ys} - {pi}, {c}");
                                    }
                                }

                                // Write palette index to sprite rom
                                spriteStream.WriteByte(Convert.ToByte(pi));
                                pos += 1;

                            }
                        }
                    }
                }
            }

            foreach (List<Color> palette in Palettes)
            {
                while (palette.Count < PaletteIndexMax)
                {
                    palette.Add(Color.FromArgb(255, 0, 255, 0));
                }
            }
            spriteStream.Close();

            if (File.Exists(palettePath))
            {
                File.Delete(palettePath);
            }
            using (FileStream paletteStream = File.OpenWrite(palettePath))
            {
                using (BinaryWriter paletteWriter = new(paletteStream, Encoding.BigEndianUnicode))
                {
                    int pi = 0;
                    foreach (List<Color> palette in Palettes)
                    {
                        for (int p = 0; p < palette.Count; p++)
                        {
                            ushort a = (ushort)(palette[p].A == 255 ? 1 : 0);

                            ushort color = (ushort)((palette[p].R / 8) |
                                                   ((palette[p].G / 8) << 5) |
                                                   ((palette[p].B / 8) << 10) |
                                                     a << 15);

                            byte high = (byte)(color >> 8);
                            byte low = (byte)color;

                           // Console.WriteLine($"PALETTE {pi}: {p} - {palette[p]} - {a} - {color.ToString("X2")} - {high} {low}");
                            paletteWriter.Write(high);
                            paletteWriter.Write(low);

                        }
                        pi++;
                    }
                }
            }
        }


        static void Main(string[] args)
        {
            CreateSpriteRom();
            CreateMusicRom();
            CreateSoundRom();
        }

    }
}
