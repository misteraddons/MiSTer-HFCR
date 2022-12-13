using System.Drawing;
using tileripper.Models;

namespace tileripper.Controls
{
    public class TilePalette : Panel
    {

        public Dictionary<int, PixelBox> Icons { get; set; }

        private Tile selectedTile;

        public Tile SelectedTile
        {
            get { return selectedTile; }
            set
            {
                if (SelectedTile != null) { Icons[SelectedTile.Index].BorderStyle = BorderStyle.None; }
                selectedTile = value;
                if (SelectedTile != null) { Icons[SelectedTile.Index].BorderStyle = BorderStyle.FixedSingle; }
            }
        }

        public TilePalette()
        {
            Icons = new Dictionary<int, PixelBox>();
        }

        internal void Clear()
        {
            foreach (var icon in Icons.Values)
            {
                Controls.Remove(icon);
                icon.Dispose();
            }
            Icons.Clear();
        }

        public int Columns { get; set; } = 6;

        internal void AddTile(Tile tile)
        {
            int nextY = Icons.Count / Columns;
            int nextX = Icons.Count - (nextY * Columns);
            PixelBox icon = new()
            {
                InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.NearestNeighbor,
                Parent = this,
                Top = nextY * 33,
                Left = nextX * 33,
                Width = 32,
                Height = 32
            };
            icon.Image = tile.Bitmap.GetBitmap();
            icon.Parent = this;
            icon.SizeMode = PictureBoxSizeMode.StretchImage;
            Icons.Add(tile.Index, icon);
            this.Controls.Add(icon);
        }

    }
}
