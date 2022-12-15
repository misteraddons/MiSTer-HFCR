using Microsoft.VisualBasic;

namespace keshiki.Models
{
    public class Scene
    {

        public Cell[,] Cells { get; set; }

        public int CellsX { get; set; }

        public int CellsY { get; set; }

        public int CellSize { get; set; }

        public string Name { get; set; }

        public List<Tile> Tiles { get; set; }

        public List<CollisionBox> Collision { get; set; }

        public Tile GetTile(int tileIndex)
        {
            return Tiles.FirstOrDefault(x => x.Index == tileIndex);
        }

        public void AddCollisionBox(CollisionBox box)
        {
            Collision.Add(box);
        }

        public void AddCollisionBox(int x, int y, int w, int h)
        {
            CollisionBox box = new CollisionBox()
            {
                Left = x,
                Top = y,
                Right = x + w,
                Bottom = y + h
            };
            Collision.Add(box);
        }
    }
}
