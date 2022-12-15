using Newtonsoft.Json;
using System.Drawing;
using System.Drawing.Imaging;
using System.Security.Cryptography.X509Certificates;
using System.Security.Policy;
using System.Text;
using System.Windows.Forms;
using keshiki.Models;

namespace keshiki
{
    public partial class Main : Form
    {
        private string SourcePath { get; set; }

        private string ResourcePath { get; set; }

        public Main()
        {
            InitializeComponent();
            string rootPath = @"..\..\..\..\..\";
            string currentProject = File.ReadAllText(rootPath + "CURRENT_PROJECT");

            ResourcePath = $@"{rootPath}resources\{currentProject}\";
            SourcePath = $@"{rootPath}src\{currentProject}\";

        }

        private string TileSourcePath => $@"{ResourcePath}tiles\\";

        private string TilemapRomPath => $@"{ResourcePath}tilemap.bin";

        private string TilemapSourcePath => $@"{SourcePath}tilemap_indexes";

        private Bitmap sceneBitmap;

        private int sceneScale = 3;

        private int sceneCellSize;

        Scene scene;

        private void Save()
        {
            File.WriteAllText($"{TileSourcePath}{scene.Name}.json", JsonConvert.SerializeObject(scene));

            // Create tilemap ROM

            if (File.Exists(TilemapRomPath)) { File.Delete(TilemapRomPath); }
            FileStream stream = File.OpenWrite(TilemapRomPath);
            BinaryWriter streamWriter = new(stream, Encoding.Default);

            foreach (Tile tile in scene.Tiles)
            {
                Bitmap tileBitmap = tile.Bitmap.GetBitmap();
                for (int y = 0; y < scene.CellSize; y++)
                {
                    for (int x = 0; x < scene.CellSize; x++)
                    {
                        Color c = tileBitmap.GetPixel(x, y);
                        ushort a = (ushort)(c.A == 255 ? 1 : 0);
                        ushort color = (ushort)((c.R / 8) | ((c.G / 8) << 5) | ((c.B / 8) << 10) | a << 15);
                        byte high = (byte)(color >> 8);
                        byte low = (byte)color;
                        streamWriter.Write(high);
                        streamWriter.Write(low);
                    }
                }
            }
            streamWriter.Dispose();

            StringBuilder builder = new();
            builder.AppendLine("#ifndef TILEMAP_INDEXES_H");
            builder.AppendLine("#define TILEMAP_INDEXES_H");
            builder.AppendLine($"#define const_tilemap_index_x_max {scene.CellsX}");
            builder.AppendLine($"#define const_tilemap_index_y_max {scene.CellsY}");
            builder.AppendLine("extern unsigned long tilemap_index[const_tilemap_index_y_max][const_tilemap_index_x_max];");
            builder.AppendLine("#endif");
            File.WriteAllText(TilemapSourcePath + ".h", builder.ToString());

            builder = new StringBuilder();
            builder.AppendLine("#ifndef TILEMAP_INDEXES_C");
            builder.AppendLine("#define TILEMAP_INDEXES_C");
            builder.AppendLine("#include \"tilemap_indexes.h\"");

            builder.AppendLine("unsigned long tilemap_index[const_tilemap_index_y_max][const_tilemap_index_x_max] = {");
            for (int y = 0; y < scene.CellsY; y++)
            {
                builder.Append('{');
                for (int x = 0; x < scene.CellsX; x++)
                {
                    builder.Append($"{scene.Cells[y, x].TileIndex}");
                    if (x < scene.CellsX - 1) { builder.Append(','); }
                }
                builder.Append('}');
                if (y < scene.CellsY - 1) { builder.AppendLine(","); }
            }
            builder.AppendLine("};");

            builder.AppendLine("#endif");
            File.WriteAllText(TilemapSourcePath + ".c", builder.ToString());

        }

        private static string GetBitmapHash(Bitmap bitmap)
        {
            StringBuilder s = new();
            for (int y = 0; y < bitmap.Height; y++)
            {
                for (int x = 0; x < bitmap.Width; x++)
                {
                    s.Append(bitmap.GetPixel(x, y).ToString());
                }
            }
            return s.ToString();
        }

        private void LoadScene(string sceneName)
        {
            scene = JsonConvert.DeserializeObject<Scene>(File.ReadAllText($"{TileSourcePath}{sceneName}.json"));
            sceneCellSize = scene.CellSize * sceneScale;
            pic_Cell.Size = new Size(sceneCellSize, sceneCellSize);
            BuildBitmap();

            Palette.Clear();
            foreach (Tile tile in scene.Tiles)
            {
                Palette.AddTile(tile);
            }
        }

        private void BuildBitmap()
        {
            sceneBitmap = new Bitmap(scene.CellSize * scene.CellsX, scene.CellSize * scene.CellsY);
            for (int y = 0; y < scene.CellsY; y++)
            {
                for (int x = 0; x < scene.CellsX; x++)
                {
                    DrawCell(x, y);
                }
            }
            pic_Scene.Image = sceneBitmap;
        }

        private void DrawCell(int x, int y)
        {
            Bitmap cellBitmap = scene.Tiles[scene.Cells[y, x].TileIndex].Bitmap.GetBitmap();
            int x1 = (x * scene.CellSize);
            int x2 = x1 + scene.CellSize;
            int y1 = (y * scene.CellSize);
            int y2 = y1 + scene.CellSize;
            int lx = 0;
            for (int cx = x1; cx < x2; cx++)
            {
                int ly = 0;
                for (int cy = y1; cy < y2; cy++)
                {
                    sceneBitmap.SetPixel(cx, cy, cellBitmap.GetPixel(lx, ly));
                    ly++;
                }
                lx++;
            }
        }

        private void Extract(string filename)
        {

            scene = new Scene
            {
                Name = filename,
                CellSize = 16,
                Tiles = new List<Tile>()
            };
            sceneBitmap = (Bitmap)Image.FromFile(TileSourcePath + scene.Name + ".png");
            scene.CellsX = sceneBitmap.Width / scene.CellSize;
            scene.CellsY = sceneBitmap.Height / scene.CellSize;
            scene.Cells = new Cell[scene.CellsY, scene.CellsX];
            sceneCellSize = scene.CellSize * sceneScale;
            pic_Cell.Size = new Size(sceneCellSize, sceneCellSize);
            Palette.Clear();

            Dictionary<string, int> tiles = new();

            var tile = new Tile(scene.Tiles.Count, new Bitmap(scene.CellSize, scene.CellSize));
            scene.Tiles.Add(tile);
            Palette.AddTile(tile);

            for (int y = 0; y < scene.CellsY; y++)
            {
                for (int x = 0; x < scene.CellsX; x++)
                {
                    Rectangle rect = new(x * scene.CellSize, y * scene.CellSize, scene.CellSize, scene.CellSize);
                    Bitmap cellBitmap = sceneBitmap.Clone(rect, PixelFormat.Format32bppArgb);
                    string hash = GetBitmapHash(cellBitmap);
                    scene.Cells[y, x] = new Cell();
                    if (tiles.ContainsKey(hash))
                    {
                        scene.Cells[y, x].TileIndex = tiles[hash];
                    }
                    else
                    {
                        tile = new Tile(scene.Tiles.Count, cellBitmap);
                        scene.Tiles.Add(tile);
                        Palette.AddTile(tile);
                        tiles.Add(hash, tile.Index);
                        scene.Cells[y, x].TileIndex = tile.Index;
                    }
                }
            }
            BuildBitmap();
            pic_Scene.Image = sceneBitmap;
            pic_Scene.Size = sceneBitmap.Size * (int)sceneScale;
        }

        private void Main_Load(object sender, EventArgs e)
        {

            pic_Cell.Parent = pic_Scene;
            pic_Cell.BackColor = Color.Transparent;

            if (File.Exists($"{TileSourcePath}{txt_SceneName.Text}.json"))
            {
                LoadScene(txt_SceneName.Text);
            }
            else
            {
                Extract(txt_SceneName.Text);
            }
            Save();

            pic_Scene.Image = sceneBitmap;
            pic_Scene.Size = sceneBitmap.Size * (int)sceneScale;

        }

        private void pic_Scene_MouseMove(object sender, MouseEventArgs e)
        {
            int x = (int)((e.X - ((PictureBox)sender).ClientRectangle.Left) / sceneCellSize);
            int y = (int)((e.Y - ((PictureBox)sender).ClientRectangle.Top) / sceneCellSize);
            pic_Cell.Left = (int)(x * sceneCellSize);
            pic_Cell.Top = (int)(y * sceneCellSize);
        }

        private void btn_Save_Click(object sender, EventArgs e)
        {
            Save();
        }

        private void pic_Cell_Click(object sender, EventArgs e)
        {
            Cell_Click(sender, e);
        }

        private void Cell_Click(object sender, EventArgs e)
        {
            MouseEventArgs me = (MouseEventArgs)e;
            int x = (int)((me.X + pic_Cell.Left) / sceneCellSize);
            int y = (int)((me.Y + pic_Cell.Top) / sceneCellSize);
            if (me.Button == MouseButtons.Left)
            {
                if (Palette.SelectedTile != null)
                {
                    scene.Cells[y, x].TileIndex = Palette.SelectedTile.Index;
                    DrawCell(x, y);
                    pic_Scene.Image = sceneBitmap;
                }
            }
            if (me.Button == MouseButtons.Right)
            {
                Palette.SelectedTile = scene.GetTile(scene.Cells[y, x].TileIndex);
            }
        }


        private void btn_Extract_Click(object sender, EventArgs e)
        {
            Extract(txt_SceneName.Text);
        }
    }
}