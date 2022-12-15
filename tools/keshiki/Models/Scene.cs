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

        public Tile GetTile(int tileIndex)
        {
            return Tiles.FirstOrDefault(x => x.Index == tileIndex);
        }
    }
}
