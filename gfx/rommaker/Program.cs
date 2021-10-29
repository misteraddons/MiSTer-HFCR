using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;

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
                Bitmap img = (Bitmap)Bitmap.FromFile(image);
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
                            if (pi > 16)
                            {
                                throw new Exception("too many colours");
                            }
                            Palette.Add(c);
                            Console.WriteLine($"Adding to palette: {image} - {pi}, {c}");
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
                using (BinaryWriter paletteWriter = new(paletteStream))
                {
                    for (int p = 0; p < Palette.Count; p++)
                    {
                        ushort color = Palette[p].A;
                        color += (ushort)(Palette[p].R << 5);
                        color += (ushort)(Palette[p].G << 10);
                        color += (ushort)(Palette[p].G << 15);
                        paletteWriter.Write(color);
                    }
                }
            }
        }


    }
}
