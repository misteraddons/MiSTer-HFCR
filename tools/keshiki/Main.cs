using keshiki.Controls;
using keshiki.Models;
using Newtonsoft.Json;
using System.DirectoryServices.ActiveDirectory;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.Text;

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

        private string CollisionSourcePath => $@"{SourcePath}collision_boxes";

        private Bitmap SceneBitmap { get; set; }

        private int SceneScale { get; set; } = 3;

        private int SceneCellSize { get; set; }

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

            // Create tilemap include
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

            // Create collision include
            builder = new();
            builder.AppendLine("#ifndef COLLISION_BOXES_H");
            builder.AppendLine("#define COLLISION_BOXES_H");
            builder.AppendLine($"#define const_collision_boxes_max {scene.Collision.Count}");
            builder.AppendLine("extern unsigned short collision_box_l[const_collision_boxes_max];");
            builder.AppendLine("extern unsigned short collision_box_t[const_collision_boxes_max];");
            builder.AppendLine("extern unsigned short collision_box_r[const_collision_boxes_max];");
            builder.AppendLine("extern unsigned short collision_box_b[const_collision_boxes_max];");
            builder.AppendLine("#endif");
            File.WriteAllText(CollisionSourcePath + ".h", builder.ToString());

            builder = new StringBuilder();
            builder.AppendLine("#ifndef COLLISION_BOXES_C");
            builder.AppendLine("#define COLLISION_BOXES_C");
            builder.AppendLine("#include \"collision_boxes.h\"");
            builder.Append("unsigned short collision_box_l[const_collision_boxes_max] = { ");
            for (int i = 0; i < scene.Collision.Count; i++)
            {
                builder.Append(scene.Collision[i].Left);
                if (i < scene.Collision.Count - 1) { builder.Append(", "); }
            }
            builder.AppendLine(" };");
            builder.Append("unsigned short collision_box_t[const_collision_boxes_max] = { ");
            for (int i = 0; i < scene.Collision.Count; i++)
            {
                builder.Append(scene.Collision[i].Top);
                if (i < scene.Collision.Count - 1) { builder.Append(", "); }
            }
            builder.AppendLine(" };");
            builder.Append("unsigned short collision_box_r[const_collision_boxes_max] = { ");
            for (int i = 0; i < scene.Collision.Count; i++)
            {
                builder.Append(scene.Collision[i].Right);
                if (i < scene.Collision.Count - 1) { builder.Append(", "); }
            }
            builder.AppendLine(" };");
            builder.Append("unsigned short collision_box_b[const_collision_boxes_max] = { ");
            for (int i = 0; i < scene.Collision.Count; i++)
            {
                builder.Append(scene.Collision[i].Bottom);
                if (i < scene.Collision.Count - 1) { builder.Append(", "); }
            }
            builder.AppendLine(" };");

            builder.AppendLine("#endif");
            File.WriteAllText(CollisionSourcePath + ".c", builder.ToString());
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
            if (scene.Collision == null) { scene.Collision = new List<CollisionBox>(); }
            SceneCellSize = scene.CellSize * SceneScale;
            RefreshBitmap();
            RefreshPalette();
            RefreshCollision();
        }

        private void RefreshPalette()
        {
            Palette.Clear();
            foreach (Tile tile in scene.Tiles) { Palette.AddTile(tile); }
        }

        private void RefreshCollision()
        {
            lst_Collision.Items.Clear();
            foreach (var box in scene.Collision)
            {
                lst_Collision.Items.Add(box);
            }

        }

        private void RefreshBitmap()
        {
            SceneBitmap = new Bitmap(scene.CellSize * scene.CellsX, scene.CellSize * scene.CellsY);
            for (int y = 0; y < scene.CellsY; y++)
            {
                for (int x = 0; x < scene.CellsX; x++)
                {
                    DrawCell(x, y);
                }
            }
            SceneBitmap = new Bitmap(SceneBitmap, new Size(SceneBitmap.Width, SceneBitmap.Height) * SceneScale);
            pic_Scene.Image = SceneBitmap;

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
                    SceneBitmap.SetPixel(cx, cy, cellBitmap.GetPixel(lx, ly));
                    ly++;
                }
                lx++;
            }
        }

        private void Extract(string filename)
        {
            if (scene == null)
            {
                scene = new Scene
                {
                    Name = filename,
                    CellSize = 16,
                    Tiles = new List<Tile>()
                };
            }
            else
            {
                scene.Name = filename;
                scene.Tiles.Clear();
            }
            SceneBitmap = (Bitmap)Image.FromFile(TileSourcePath + scene.Name + ".png");
            scene.CellsX = SceneBitmap.Width / scene.CellSize;
            scene.CellsY = SceneBitmap.Height / scene.CellSize;
            scene.Cells = new Cell[scene.CellsY, scene.CellsX];
            SceneCellSize = scene.CellSize * SceneScale;
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
                    Bitmap cellBitmap = SceneBitmap.Clone(rect, PixelFormat.Format32bppArgb);
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
            RefreshBitmap();
            pic_Scene.Image = SceneBitmap;
            pic_Scene.Top = 4;
            pic_Scene.Left = 4;
            pic_Scene.Size = SceneBitmap.Size;
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

            pic_Scene.Image = SceneBitmap;
            pic_Scene.Size = SceneBitmap.Size * (int)SceneScale;

            SetEditMode(EditMode.Tiles);

        }


        private int mouseX { get; set; }
        private int mouseY { get; set; }
        private int mouseCellX { get; set; }
        private int mouseCellY { get; set; }

        private void pic_Cell_MouseMove(object sender, MouseEventArgs e)
        {
            mouseX = (((PictureBox)sender).Left + e.X) / SceneScale;
            mouseY = (((PictureBox)sender).Top + e.Y) / SceneScale;
            mouseCellX = mouseX / scene.CellSize;
            mouseCellY = mouseY / scene.CellSize;
            MouseHover();
        }
        private void pic_Scene_MouseMove(object sender, MouseEventArgs e)
        {
            mouseX = (e.X - ((PictureBox)sender).ClientRectangle.Left) / SceneScale;
            mouseY = (e.Y - ((PictureBox)sender).ClientRectangle.Top) / SceneScale;
            mouseCellX = mouseX / scene.CellSize;
            mouseCellY = mouseY / scene.CellSize;
            MouseHover();
        }

        private void MouseHover()
        {
            switch (Interaction)
            {
                case InteractMode.TileSelect:
                    pic_Cell.Left = (int)(mouseCellX * SceneCellSize);
                    pic_Cell.Top = (int)(mouseCellY * SceneCellSize);
                    break;

                case InteractMode.CollisionBoxBegin:
                    pic_Cell.Left = (int)(mouseX) * SceneScale;
                    pic_Cell.Top = (int)(mouseY) * SceneScale;
                    txt_Collision.Text = $"{mouseX}/{mouseY}";
                    break;

                case InteractMode.CollisionBoxDraw:

                    DrawBoxW = Math.Abs(mouseX - DrawBoxX);
                    DrawBoxH = Math.Abs(mouseY - DrawBoxY);
                    ActiveBox.Left = (mouseX > DrawBoxX) ? DrawBoxX : mouseX;
                    ActiveBox.Top = (mouseY > DrawBoxY) ? DrawBoxY : mouseY;
                    ActiveBox.Right = ActiveBox.Left + DrawBoxW;
                    ActiveBox.Bottom = ActiveBox.Top + DrawBoxH;
                    pic_Cell.Left = ActiveBox.Left * SceneScale;
                    pic_Cell.Top = ActiveBox.Top * SceneScale;
                    pic_Cell.Width = DrawBoxW * SceneScale;
                    pic_Cell.Height = DrawBoxH * SceneScale;

                    txt_Collision.Text = $"{mouseX}/{mouseY} > {DrawBoxW}/{DrawBoxH}";
                    break;
            }
        }

        private void btn_Save_Click(object sender, EventArgs e)
        {
            Save();
        }

        private void pic_Cell_Click(object sender, EventArgs e)
        {
            SceneClick(sender, e);
        }

        private void SceneClick(object sender, EventArgs e)
        {
            MouseEventArgs me = (MouseEventArgs)e;

            switch (Interaction)
            {
                case InteractMode.TileSelect:

                    if (me.Button == MouseButtons.Left)
                    {
                        if (Palette.SelectedTile != null)
                        {
                            scene.Cells[mouseCellY, mouseCellX].TileIndex = Palette.SelectedTile.Index;
                            RefreshBitmap();
                        }
                    }
                    if (me.Button == MouseButtons.Right)
                    {
                        Palette.SelectedTile = scene.GetTile(scene.Cells[mouseCellY, mouseCellX].TileIndex);

                    }
                    break;

                case InteractMode.CollisionBoxBegin:
                    if (me.Button == MouseButtons.Left)
                    {
                        DrawBoxX = mouseX;
                        DrawBoxY = mouseY;
                        DrawBoxW = 0;
                        DrawBoxH = 0;
                        ActiveBox = new CollisionBox();
                        Interaction = InteractMode.CollisionBoxDraw;
                    }
                    if (me.Button == MouseButtons.Right)
                    {
                        Interaction = InteractMode.None;
                        HideCell();
                        ShowCollision();
                    }
                    break;

                case InteractMode.CollisionBoxDraw:
                    if (me.Button == MouseButtons.Left)
                    {
                        Interaction = InteractMode.None;
                        scene.AddCollisionBox(ActiveBox);
                        ShowCollision();
                        HideCell();
                        RefreshCollision();
                    }
                    if (me.Button == MouseButtons.Right)
                    {
                        Interaction = InteractMode.None;
                        HideCell();
                        ShowCollision();
                    }
                    break;
            }

        }

        private void HideCell()
        {
            pic_Cell.Visible = false;
        }

        private int DrawBoxX { get; set; }

        private int DrawBoxY { get; set; }

        private int DrawBoxW { get; set; }

        private int DrawBoxH { get; set; }

        private CollisionBox ActiveBox { get; set; }


        private void btn_Extract_Click(object sender, EventArgs e)
        {
            Extract(txt_SceneName.Text);
        }

        enum EditMode
        {
            Tiles,
            Collision
        }

        enum InteractMode
        {
            None,
            TileSelect,
            CollisionBoxBegin,
            CollisionBoxDraw,
        }

        private EditMode Mode = EditMode.Tiles;
        private InteractMode Interaction;

        private void tabs_SelectedIndexChanged(object sender, EventArgs e)
        {
            var tab = tabs.SelectedTab;
            if (tab.Text == "Tiles") { SetEditMode(EditMode.Tiles); }
            if (tab.Text == "Collision") { SetEditMode(EditMode.Collision); }
        }

        private void SetEditMode(EditMode mode)
        {
            Mode = mode;
            switch (mode)
            {
                case EditMode.Tiles:
                    HideCollision();
                    ShowCell(images.Images[0], new Size(SceneCellSize, SceneCellSize));
                    Interaction = InteractMode.TileSelect;
                    break;
                case EditMode.Collision:
                    ShowCollision();
                    Interaction = InteractMode.None;
                    HideCell();
                    break;
            }
        }

        private void ShowCell(Image image, Size size)
        {
            pic_Cell.Image = image;
            pic_Cell.Visible = true;
            pic_Cell.Size = size;
        }

        private void ShowCollision()
        {
            HideCollision();
            if (scene.Collision == null) { scene.Collision = new List<CollisionBox>(); }
            foreach (var box in scene.Collision)
            {
                int imageIndex = (box == ActiveBox) ? 2 : 1;
                Image image = images.Images[imageIndex];
                PixelBox b = new()
                {
                    Parent = pic_Scene,
                    Left = box.Left * SceneScale,
                    Top = box.Top * SceneScale,
                    Width = (box.Right - box.Left) * SceneScale,
                    Height = (box.Bottom - box.Top) * SceneScale,
                    Image = image,
                    SizeMode = PictureBoxSizeMode.StretchImage,
                    InterpolationMode = InterpolationMode.NearestNeighbor
                };
                pic_Scene.Controls.Add(b);
                CollisionBoxes.Add(b);
            }
        }

        List<PixelBox> CollisionBoxes = new List<PixelBox>();

        private void HideCollision()
        {
            foreach (var box in CollisionBoxes)
            {
                pic_Scene.Controls.Remove(box);
                box.Dispose();
            }
            CollisionBoxes.Clear();
        }

        private void btn_AddCollision_Click(object sender, EventArgs e)
        {
            Interaction = InteractMode.CollisionBoxBegin;
            ShowCell(images.Images[2], new Size(4, 4));
            lst_Collision.SelectedIndices.Clear();
        }

        private void pic_Scene_MouseClick(object sender, MouseEventArgs e)
        {
            SceneClick(sender, e);
        }


        private bool CollisionBoxUpdating { get; set; }

        private void lst_Collision_SelectedIndexChanged(object sender, EventArgs e)
        {
            btn_DeleteBox.Enabled = false;
            if (lst_Collision.SelectedIndices.Count != 0)
            {
                btn_DeleteBox.Enabled = true;
                CollisionBoxUpdating = true;
                ActiveBox = (CollisionBox)lst_Collision.SelectedItem;
                txt_CollisionBox_Left.Value = ActiveBox.Left;
                txt_CollisionBox_Top.Value = ActiveBox.Top;
                txt_CollisionBox_Right.Value = ActiveBox.Right;
                txt_CollisionBox_Bottom.Value = ActiveBox.Bottom;
                ShowCollision();
                CollisionBoxUpdating = false;
            }
        }


        private void UpdateCollisionBox()
        {
            ActiveBox.Left = (int)txt_CollisionBox_Left.Value;
            ActiveBox.Top = (int)txt_CollisionBox_Top.Value;
            ActiveBox.Right = (int)txt_CollisionBox_Right.Value;
            ActiveBox.Bottom = (int)txt_CollisionBox_Bottom.Value;
            var box = scene.Collision.Where(x => x == ActiveBox).FirstOrDefault();
            ShowCollision();
            RefreshCollision();
        }

        private void txt_CollisionBox_Left_ValueChanged(object sender, EventArgs e)
        {
            if (!CollisionBoxUpdating) UpdateCollisionBox();
        }
        private void txt_CollisionBox_Top_ValueChanged(object sender, EventArgs e)
        {
            if (!CollisionBoxUpdating) UpdateCollisionBox();
        }

        private void txt_CollisionBox_Right_ValueChanged(object sender, EventArgs e)
        {
            if (!CollisionBoxUpdating) UpdateCollisionBox();
        }

        private void txt_CollisionBox_Bottom_ValueChanged(object sender, EventArgs e)
        {
            if (!CollisionBoxUpdating) UpdateCollisionBox();
        }

        private void btn_DeleteBox_Click(object sender, EventArgs e)
        {
            scene.Collision.Remove(ActiveBox);
            RefreshCollision();
            ShowCollision();
        }
    }
}