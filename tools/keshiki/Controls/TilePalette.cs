using System.Drawing;
using keshiki.Models;

namespace keshiki.Controls
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

        public int TileSize { get; set; } = 48;

        internal void AddTile(Tile tile)
        {
            int nextY = Icons.Count / Columns;
            int nextX = Icons.Count - (nextY * Columns);
            PixelBox icon = new()
            {
                InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.NearestNeighbor,
                Parent = this,
                Top = nextY * (TileSize+1),
                Left = nextX * (TileSize + 1),
                Width = TileSize,
                Height = TileSize,
                Tag = tile
            };
            icon.Image = tile.Bitmap.GetBitmap();
            icon.Parent = this;
            icon.SizeMode = PictureBoxSizeMode.StretchImage;
            icon.Click += Icon_Click;
            Icons.Add(tile.Index, icon);
            this.Controls.Add(icon);
        }

        private void Icon_Click(object? sender, EventArgs e)
        {
            SelectedTile = (Tile)((PixelBox)sender).Tag;
        }
    }
}
