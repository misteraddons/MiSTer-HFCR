using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;

namespace rommaker
{
    class Program
    {
        static readonly string tilemapRomPath = @"..\..\..\..\gfx\tilemap.bin";
        static readonly string tilemapPath = @"..\..\..\..\gfx\tilemap\tilemap.png";

        static readonly string spriteRomPath = @"..\..\..\..\gfx\sprite.bin";

        static readonly string spritePath = @"..\..\..\..\gfx\images\";
        static readonly string palettePath = @"..\..\..\..\gfx\palette.bin";
        static readonly string spriteSourcePath = @"..\..\..\..\src\sprite_images";

        static readonly string musicPath = @"..\..\..\..\music\";
        static readonly string musicTrackListPath = @"..\..\..\..\music\tracks.txt";
        static readonly string musicRomPath = @"..\..\..\..\music\music.bin";
        static readonly string musicSourcePath = @"..\..\..\..\src\music_tracks";

        static readonly string soundPath = @"..\..\..\..\sound\";
        static readonly string soundListPath = @"..\..\..\..\sound\samples.txt";
        static readonly string soundRomPath = @"..\..\..\..\sound\sound.bin";
        static readonly string soundSourcePath = @"..\..\..\..\src\sound_samples";

        static readonly int PaletteMax = 4;
        static readonly int PaletteIndexMax = 32;

        static readonly List<List<Color>> Palettes = new();

        static void CreateMusicRom()
        {
            Console.WriteLine("CREATING MUSIC ROM");
            if (File.Exists(musicRomPath)) { File.Delete(musicRomPath); }

            // Read track list
            string[] tracks = File.ReadAllLines(musicTrackListPath);

            List<byte> trackData = new();
            string[] trackPos = new string[tracks.Length];

            int t = 0;
            uint p = 0;
            foreach (string track in tracks)
            {
                string file = track.Split("#")[0];
                byte[] data = File.ReadAllBytes(musicPath + file);
                trackData.AddRange(data);
                trackPos[t] = p + "u";
                Console.WriteLine($"\t{t} - {p} > {file}");
                p += (uint)data.Length;
                t++;
            }

            StringBuilder builder = new();
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
            Console.WriteLine("CREATING SOUND ROM");
            if (File.Exists(soundRomPath)) { File.Delete(soundRomPath); }

            // Read sample list
            string[] samples = File.ReadAllLines(soundListPath);

            List<byte> soundData = new();
            string[] soundPos = new string[samples.Length];
            string[] soundLen = new string[samples.Length];
            string command = $@"C:\Program Files (x86)\sox-14-4-2\sox.exe";
            int t = 0;
            uint p = 0;

            StringBuilder builder = new();
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
                Process.Start(command, args).WaitForExit();
                byte[] data = File.ReadAllBytes($"{soundPath}{file}.vox");
                soundData.AddRange(data);
                soundPos[t] = p + "u";
                uint l = (uint)data.Length;
                soundLen[t] = l + "u";
                builder.AppendLine($"#define const_sound_{name} {t}");
                Console.WriteLine($"\t{t} - {p} > {file}");
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
            BinaryWriter spriteStreamWriter = new(spriteStream, Encoding.Default);

            uint pos = 0;
            Dictionary<string, string> spriteSourceItems = new Dictionary<string, string>();


            int[] groups = { 32, 16, 8 };

            Dictionary<int, MemoryStream> groupStreams = new();
            int groupIndex = groups.Length - 1;
            for (int gi = 0; gi < groups.Length; gi++)
            {
                int g = groups[gi];
                int index = 0;
                ushort groupStartPos = (ushort)(pos + (groups.Length * 2));
                byte[] groupStartBytes = BitConverter.GetBytes(groupStartPos);
                Console.WriteLine($"Starting image group {g} at {groupStartPos}");
                spriteStreamWriter.Write(groupStartBytes[1]); // Write start point for size group
                spriteStreamWriter.Write(groupStartBytes[0]); // Write start point for size group

                MemoryStream groupStream = new MemoryStream();
                ushort groupLen = 0;
                foreach (string image in Directory.GetFiles(spritePath, "*.png", SearchOption.TopDirectoryOnly).Where(x => x.Contains($"\\{g}_")))
                {
                    Bitmap img = new(image);

                    // Remove extension
                    string title = image[0..^4];

                    // Detect palette
                    if (!title.Contains('#'))
                    {
                        throw new Exception("No palette data");
                    }
                    string[] paletteParts = title.Split("#");
                    title = paletteParts[0];
                    int paletteIndex = int.Parse(paletteParts[1]) - 1;

                    // Get name
                    int size = int.Parse(title[(title.LastIndexOf("\\") + 1)..].Split('_')[0]);
                    string name = title.Split("-")[0].Split("_")[1];

                    // Detect slices
                    int imageSizeX = img.Width;
                    int imageSizeY = img.Height;
                    int slicesX = imageSizeX / size;
                    int slicesY = imageSizeY / size;

                    // Add header items
                    spriteSourceItems.Add($"sprite_index_{name}_first", index.ToString());
                    spriteSourceItems.Add($"sprite_index_{name}_count", $"{slicesX * slicesY}");
                    spriteSourceItems.Add($"sprite_index_{name}_last", $"{index + (slicesX * slicesY) - 1}");
                    spriteSourceItems.Add($"sprite_palette_{name}", $"{paletteIndex}");
                    spriteSourceItems.Add($"sprite_size_{name}", $"{gi}");

                    for (int ys = 0; ys < slicesY; ys++)
                    {
                        for (int xs = 0; xs < slicesX; xs++)
                        {
                            Console.WriteLine($"{index}: {name} - {xs},{ys} --> {pos}");
                            int ymin = ys * size;
                            int ymax = ymin + size;
                            int xmin = xs * size;
                            int xmax = xmin + size;
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
                                    groupStream.WriteByte(Convert.ToByte(pi));
                                    pos += 1;
                                    groupLen += 1;
                                }
                            }
                            index++;
                        }
                    }
                }
                Console.WriteLine($"Ending image group {g} - length = {groupLen}");
                groupIndex--;
                groupStreams.Add(g, groupStream);
            }

            foreach (int g in groups)
            {
                spriteStreamWriter.Write(groupStreams[g].ToArray());
            }
            spriteStreamWriter.Dispose();

            StringBuilder builder = new();
            builder.AppendLine("#ifndef SPRITE_IMAGES_H");
            builder.AppendLine("#define SPRITE_IMAGES_H");
            foreach (string v in spriteSourceItems.Keys)
            {
                builder.AppendLine("#define " + v + " " + spriteSourceItems[v]);
            }
            builder.AppendLine("#endif");
            File.WriteAllText(spriteSourcePath + ".h", builder.ToString());

            //            builder = new StringBuilder();
            //builder.AppendLine("#ifndef SPRITE_IMAGES_C");
            //builder.AppendLine("#define SPRITE_IMAGES_C");
            //builder.AppendLine("#include \"sprite_images.h\"");
            //foreach (string v in spriteSourceItems.Keys)
            //{
            //    builder.AppendLine("extern " + v + " " + spriteSourceItems[v]);
            //}
            //builder.AppendLine("#endif");
            //File.WriteAllText(spriteSourcePath + ".c", builder.ToString());


            // Palettes
            foreach (List<Color> palette in Palettes)
            {
                while (palette.Count < PaletteIndexMax)
                {
                    palette.Add(Color.FromArgb(255, 0, 255, 0));
                }
            }

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


        static void CreateTilemapRom()
        {

            if (File.Exists(tilemapRomPath)) { File.Delete(tilemapRomPath); }

            FileStream stream = File.OpenWrite(tilemapRomPath);
            BinaryWriter streamWriter = new(stream, Encoding.Default);

            uint pos = 0;
            Bitmap img = new(tilemapPath);
            int size = 16;
            int slicesX = img.Width / size;
            int slicesY = img.Height / size;

            for (int ys = 0; ys < slicesY; ys++)
            {
                for (int xs = 0; xs < slicesX; xs++)
                {
                    int ymin = ys * size;
                    int ymax = ymin + size;
                    int xmin = xs * size;
                    int xmax = xmin + size;
                    for (int y = ymin; y < ymax; y++)
                    {
                        for (int x = xmin; x < xmax; x++)
                        {


                            Color c = img.GetPixel(x, y);
                            ushort a = (ushort)(c.A == 255 ? 1 : 0);
                            ushort color = (ushort)((c.R / 8) |
                                                   ((c.G / 8) << 5) |
                                                   ((c.B / 8) << 10) |
                                                     a << 15);

                            byte high = (byte)(color >> 8);
                            byte low = (byte)color;
                            streamWriter.Write(high);
                            streamWriter.Write(low);

                            pos += 1;
                        }
                    }
                }
            }

            streamWriter.Dispose();
        }


        static void Main(string[] args)
        {
            CreateSpriteRom();
            CreateTilemapRom();
            CreateMusicRom();
            CreateSoundRom();
        }

    }
}
