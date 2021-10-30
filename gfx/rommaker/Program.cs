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

        static void Main(string[] args)
        {

            Palette.Clear();

            
            FileStream spriteStream = File.OpenWrite(@"C:\repos\Aznable\gfx\sprite.bin");


            Palette.Add(Color.FromArgb(0,0,0,0));

            foreach (string image in Directory.GetFiles(@"C:\repos\Aznable\gfx\images\"))
            {
                Bitmap img = new(image);
                for (int y = 0; y < img.Height; y++)
                {
                    for (int x = 0; x < img.Width; x++)
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
                            if (pi == 16)
                            {
                                //   throw new Exception("too many colours");
                                Console.WriteLine($"Palette full: {image} - {pi}, {c}");
                                pi = 0;
                            }
                            else
                            {
                                Palette.Add(c);
                                Console.WriteLine($"Adding to palette: {image} - {pi}, {c}");
                            }
                        }

                        // Write palette index to sprite rom
                        spriteStream.WriteByte(Convert.ToByte(pi));

                    }
                }
            }

            while (Palette.Count < 16)
            {
                Palette.Add(Color.FromArgb(255, 255, 0, 255));
            }
            spriteStream.Close();

            string palettePath = @"C:\repos\Aznable\gfx\palette.bin";
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

                        ushort color = (ushort)((Palette[p].R /8) |
                                               ((Palette[p].G /8) << 5) |
                                               ((Palette[p].B /8) << 10) |
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
