using Newtonsoft.Json;
using System.Drawing.Imaging;
using System.Security.Cryptography.X509Certificates;
using System.Security.Policy;
using System.Text;
using System.Windows.Forms;
using tileripper.Models;

namespace tileripper
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private readonly string rootPath = "C:\\repos\\Aznable\\resources\\raiders\\tiles\\";

        private Bitmap sceneBitmap;

        private int sceneScale = 3;
        private int sceneCellSize;

        Scene scene;

        private void Save()
        {
            File.WriteAllText($"{rootPath}{scene.Name}.json", JsonConvert.SerializeObject(scene));
        }


        private string GetBitmapHash(Bitmap bitmap)
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
            scene = JsonConvert.DeserializeObject<Scene>(File.ReadAllText($"{rootPath}{sceneName}.json"));
            sceneCellSize = scene.CellSize * sceneScale;
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
        }

        private void DrawCell(int x, int y)
        {
            Bitmap cellBitmap = scene.Tiles[scene.Cells[y, x].TileIndex].Bitmap.GetBitmap();
            int x1 = (x * scene.CellSize);
            int x2 = x1 + scene.CellSize;
            int y1 = (y * scene.CellSize);
            int y2 = y1 + scene.CellSize;
            int lx = 0; int ly = 0;
            for (int cx = x1; cx < x2; cx++)
            {
                ly = 0;
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
                CellSize = 8,
                Tiles = new List<Tile>()
            };
            sceneBitmap = (Bitmap)Image.FromFile(rootPath + scene.Name + ".png");
            scene.CellsX = sceneBitmap.Width / scene.CellSize;
            scene.CellsY = sceneBitmap.Height / scene.CellSize;
            scene.Cells = new Cell[scene.CellsY, scene.CellsX];
            sceneCellSize = scene.CellSize * sceneScale;
            scene.Tiles.Clear();

            Dictionary<string, int> tiles = new();
            for (int y = 0; y < scene.CellsY; y++)
            {
                for (int x = 0; x < scene.CellsX; x++)
                {
                    Rectangle rect = new(x * scene.CellSize, y * scene.CellSize, scene.CellSize, scene.CellSize);
                    Bitmap cellBitmap = sceneBitmap.Clone(rect, PixelFormat.Format32bppArgb);
                    string hash = GetBitmapHash(cellBitmap);
                    Bitmap cellBitmap2 = new(cellBitmap, cellBitmap.Size.Width * 2, cellBitmap.Size.Height * 2);
                    ListViewItem li = new();
                    scene.Cells[y, x] = new Cell();
                    if (tiles.ContainsKey(hash))
                    {
                        scene.Cells[y, x].TileIndex = tiles[hash];
                        li.ImageIndex = tiles[hash];
                    }
                    else
                    {
                        var tile = new Tile(li.ImageIndex, cellBitmap);
                        scene.Tiles.Add(tile);
                        Palette.AddTile(tile);
                        tiles.Add(hash, li.ImageIndex);
                        scene.Cells[y, x].TileIndex = li.ImageIndex;
                    }
                }
            }
        }

        private void Main_Load(object sender, EventArgs e)
        {



            if (File.Exists($"{rootPath}{txt_SceneName.Text}.json"))
            {
                LoadScene(txt_SceneName.Text);
            }
            else
            {
                Extract(txt_SceneName.Text);
            }

            Save();

            pic_Cell.Parent = pic_Scene;
            pic_Cell.BackColor = Color.Transparent;
            pic_Cell.Size = new Size(sceneCellSize, sceneCellSize);

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


        private void tilePalette1_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}