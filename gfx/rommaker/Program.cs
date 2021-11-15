using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;

namespace rommaker
{
    class Program
    {

        static List<Color> Palette = new List<Color>();

        static int PaletteMax = 32;

        static void Main(string[] args)
        {

            Palette.Clear();

            string spriteRomPath = @"C:\repos\Aznable\gfx\sprite.bin";
            string palettePath = @"C:\repos\Aznable\gfx\palette.bin";

            if (File.Exists(spriteRomPath)) { File.Delete(spriteRomPath); }
            if (File.Exists(palettePath)) { File.Delete(palettePath); }

            Palette.Add(Color.FromArgb(0, 0, 0, 0));

            FileStream spriteStream = File.OpenWrite(spriteRomPath);

            uint pos = 0;

            foreach (string image in Directory.GetFiles(@"C:\repos\Aznable\gfx\images\","*.png", SearchOption.TopDirectoryOnly))
            {
                Bitmap img = new(image);

                int slicesX = 1;
                int slicesY = 1;

                if (image.Contains("-"))
                {
                    string end = image.Split("-")[1];
                    end = end.Substring(0, end.Length - 4);
                    string[] parts = end.Split("_");
                    slicesX = int.Parse(parts[0]);
                    slicesY = int.Parse(parts[1]);
                }
                int sizeX = img.Width / slicesX;
                int sizeY = img.Height / slicesY;

                for (int ys = 0; ys < slicesY; ys++)
                {
                    for (int xs = 0; xs < slicesX; xs++)
                    {
                        Console.WriteLine($"Starting image: {image} - {xs},{ys} --> {pos}");
                        int ymin = ys * sizeY;
                        int ymax = ymin + sizeY ;
                        int xmin = xs * sizeX;
                        int xmax = xmin + sizeX ;
                        for (int y = ymin; y < ymax; y++)
                        {
                            for (int x = xmin; x < xmax; x++)
                            {

                                Color c = img.GetPixel(x, y);
                                // Find colour in palette
                                int pi = -1;
                                for (int ci = 0; ci < Palette.Count; ci++)
                                {
                                    if (Palette[ci] == c)
                                    {
                                        pi = ci;
                                    }
                                }
                                // Colour not found, add to paletta
                                if (pi == -1)
                                {
                                    pi = Palette.Count;
                                    if (pi == PaletteMax)
                                    {
                                        //   throw new Exception("too many colours");
                                        Console.WriteLine($"Palette full: {image} - {xs},{ys} - {pi}, {c}");
                                        pi = 0;
                                    }
                                    else
                                    {
                                        Palette.Add(c);
                                        Console.WriteLine($"Adding to palette: {image} - {xs},{ys} - {pi}, {c}");
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

            while (Palette.Count < PaletteMax)
            {
                Palette.Add(Color.FromArgb(255, 255, 0, 255));
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
                    for (int p = 0; p < Palette.Count; p++)
                    {
                        ushort a = (ushort)(Palette[p].A == 255 ? 1 : 0);

                        ushort color = (ushort)((Palette[p].R / 8) |
                                               ((Palette[p].G / 8) << 5) |
                                               ((Palette[p].B / 8) << 10) |
                                                 a << 15);

                        byte high = (byte)(color >> 8);
                        byte low = (byte)color;

                        Console.WriteLine($"{p} - {Palette[p]} - {a} - {color.ToString("X2")} - {high} {low}");
                        paletteWriter.Write(high);
                        paletteWriter.Write(low);
                    }
                }
            }
        }


    }
}
