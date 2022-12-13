using System.Runtime.Serialization;

namespace tileripper.Models
{
    public class SerializedBitmap
    {

        public int Width { get; set; }

        public int Height { get; set; }


        public BitmapPixel[,] Pixels { get; set; }

        private Bitmap bitmap;

        public SerializedBitmap()
        {

        }

        public SerializedBitmap(Bitmap bitmap)
        {
            this.bitmap = bitmap;
            this.Width= bitmap.Width;
            this.Height= bitmap.Height;
            ReadBitmap();
        }

        private void ReadBitmap()
        {
            Pixels = new BitmapPixel[bitmap.Height, bitmap.Width];
            for (int y = 0; y < bitmap.Height; y++)
            {
                for (int x = 0; x < bitmap.Width; x++)
                {
                    Pixels[y, x] = new(bitmap.GetPixel(x, y));
                }
            }
        }

        public Bitmap GetBitmap()
        {
            if (bitmap == null)
            {
                bitmap = new Bitmap(Width, Height);
                for (int y = 0; y < bitmap.Height; y++)
                {
                    for (int x = 0; x < bitmap.Width; x++)
                    {
                        bitmap.SetPixel(x, y, Pixels[y, x].Color);
                    }
                }
            }
            return bitmap;
        }
    }
}