namespace tileripper.Models
{
    public class Tile
    {

        public int Index { get; set; }

        public SerializedBitmap Bitmap { get; set; }

        public Tile()
        {

        }

        public Tile(int index, Bitmap bitmap)
        {
            this.Index = index;
            this.Bitmap = new(bitmap);
        }
    }
}