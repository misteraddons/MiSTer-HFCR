using keshiki.Controls;

namespace keshiki
{
    partial class Main
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Main));
            this.pic_Scene = new keshiki.Controls.PixelBox();
            this.txt_SceneName = new System.Windows.Forms.TextBox();
            this.pic_Cell = new keshiki.Controls.PixelBox();
            this.btn_Save = new System.Windows.Forms.Button();
            this.Palette = new keshiki.Controls.TilePalette();
            this.btn_Extract = new System.Windows.Forms.Button();
            this.scroll_Scene = new keshiki.Controls.ScrollPanel();
            this.tabs = new System.Windows.Forms.TabControl();
            this.tab_palette = new System.Windows.Forms.TabPage();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.label3 = new System.Windows.Forms.Label();
            this.txt_CollisionBox_Bottom = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.txt_CollisionBox_Right = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.txt_CollisionBox_Top = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.txt_CollisionBox_Left = new System.Windows.Forms.NumericUpDown();
            this.txt_Collision = new System.Windows.Forms.TextBox();
            this.btn_AddCollision = new System.Windows.Forms.Button();
            this.lst_Collision = new System.Windows.Forms.ListBox();
            this.images = new System.Windows.Forms.ImageList(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.pic_Scene)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_Cell)).BeginInit();
            this.scroll_Scene.SuspendLayout();
            this.tabs.SuspendLayout();
            this.tab_palette.SuspendLayout();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txt_CollisionBox_Bottom)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txt_CollisionBox_Right)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txt_CollisionBox_Top)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txt_CollisionBox_Left)).BeginInit();
            this.SuspendLayout();
            // 
            // pic_Scene
            // 
            this.pic_Scene.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.NearestNeighbor;
            this.pic_Scene.Location = new System.Drawing.Point(9, 12);
            this.pic_Scene.Margin = new System.Windows.Forms.Padding(0);
            this.pic_Scene.Name = "pic_Scene";
            this.pic_Scene.Size = new System.Drawing.Size(771, 581);
            this.pic_Scene.TabIndex = 0;
            this.pic_Scene.TabStop = false;
            this.pic_Scene.MouseClick += new System.Windows.Forms.MouseEventHandler(this.pic_Scene_MouseClick);
            this.pic_Scene.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pic_Scene_MouseMove);
            // 
            // txt_SceneName
            // 
            this.txt_SceneName.Location = new System.Drawing.Point(1, 2);
            this.txt_SceneName.Name = "txt_SceneName";
            this.txt_SceneName.Size = new System.Drawing.Size(413, 23);
            this.txt_SceneName.TabIndex = 2;
            this.txt_SceneName.Text = "cave";
            // 
            // pic_Cell
            // 
            this.pic_Cell.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.NearestNeighbor;
            this.pic_Cell.Location = new System.Drawing.Point(783, 27);
            this.pic_Cell.Name = "pic_Cell";
            this.pic_Cell.Size = new System.Drawing.Size(48, 48);
            this.pic_Cell.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pic_Cell.TabIndex = 3;
            this.pic_Cell.TabStop = false;
            this.pic_Cell.Click += new System.EventHandler(this.pic_Cell_Click);
            this.pic_Cell.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pic_Cell_MouseMove);
            // 
            // btn_Save
            // 
            this.btn_Save.Location = new System.Drawing.Point(512, 2);
            this.btn_Save.Name = "btn_Save";
            this.btn_Save.Size = new System.Drawing.Size(88, 23);
            this.btn_Save.TabIndex = 4;
            this.btn_Save.Text = "Save";
            this.btn_Save.UseVisualStyleBackColor = true;
            this.btn_Save.Click += new System.EventHandler(this.btn_Save_Click);
            // 
            // Palette
            // 
            this.Palette.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.Palette.AutoScroll = true;
            this.Palette.Columns = 6;
            this.Palette.Icons = ((System.Collections.Generic.Dictionary<int, keshiki.Controls.PixelBox>)(resources.GetObject("Palette.Icons")));
            this.Palette.Location = new System.Drawing.Point(6, 6);
            this.Palette.Name = "Palette";
            this.Palette.SelectedTile = null;
            this.Palette.Size = new System.Drawing.Size(320, 560);
            this.Palette.TabIndex = 5;
            this.Palette.TileSize = 48;
            // 
            // btn_Extract
            // 
            this.btn_Extract.Location = new System.Drawing.Point(418, 2);
            this.btn_Extract.Name = "btn_Extract";
            this.btn_Extract.Size = new System.Drawing.Size(88, 23);
            this.btn_Extract.TabIndex = 6;
            this.btn_Extract.Text = "Extract";
            this.btn_Extract.UseVisualStyleBackColor = true;
            this.btn_Extract.Click += new System.EventHandler(this.btn_Extract_Click);
            // 
            // scroll_Scene
            // 
            this.scroll_Scene.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.scroll_Scene.AutoScroll = true;
            this.scroll_Scene.Controls.Add(this.pic_Scene);
            this.scroll_Scene.Location = new System.Drawing.Point(0, 26);
            this.scroll_Scene.Name = "scroll_Scene";
            this.scroll_Scene.Size = new System.Drawing.Size(797, 604);
            this.scroll_Scene.TabIndex = 7;
            // 
            // tabs
            // 
            this.tabs.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tabs.Controls.Add(this.tab_palette);
            this.tabs.Controls.Add(this.tabPage2);
            this.tabs.Location = new System.Drawing.Point(803, 29);
            this.tabs.Name = "tabs";
            this.tabs.SelectedIndex = 0;
            this.tabs.Size = new System.Drawing.Size(341, 601);
            this.tabs.TabIndex = 8;
            this.tabs.SelectedIndexChanged += new System.EventHandler(this.tabs_SelectedIndexChanged);
            // 
            // tab_palette
            // 
            this.tab_palette.Controls.Add(this.Palette);
            this.tab_palette.Location = new System.Drawing.Point(4, 24);
            this.tab_palette.Name = "tab_palette";
            this.tab_palette.Padding = new System.Windows.Forms.Padding(3);
            this.tab_palette.Size = new System.Drawing.Size(333, 573);
            this.tab_palette.TabIndex = 0;
            this.tab_palette.Text = "Tiles";
            this.tab_palette.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.label3);
            this.tabPage2.Controls.Add(this.txt_CollisionBox_Bottom);
            this.tabPage2.Controls.Add(this.label4);
            this.tabPage2.Controls.Add(this.txt_CollisionBox_Right);
            this.tabPage2.Controls.Add(this.label2);
            this.tabPage2.Controls.Add(this.txt_CollisionBox_Top);
            this.tabPage2.Controls.Add(this.label1);
            this.tabPage2.Controls.Add(this.txt_CollisionBox_Left);
            this.tabPage2.Controls.Add(this.txt_Collision);
            this.tabPage2.Controls.Add(this.btn_AddCollision);
            this.tabPage2.Controls.Add(this.lst_Collision);
            this.tabPage2.Location = new System.Drawing.Point(4, 24);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(333, 573);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Collision";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(267, 506);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 15);
            this.label3.TabIndex = 10;
            this.label3.Text = "Bottom";
            // 
            // txt_CollisionBox_Bottom
            // 
            this.txt_CollisionBox_Bottom.Location = new System.Drawing.Point(267, 523);
            this.txt_CollisionBox_Bottom.Maximum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.txt_CollisionBox_Bottom.Name = "txt_CollisionBox_Bottom";
            this.txt_CollisionBox_Bottom.Size = new System.Drawing.Size(59, 23);
            this.txt_CollisionBox_Bottom.TabIndex = 9;
            this.txt_CollisionBox_Bottom.ValueChanged += new System.EventHandler(this.txt_CollisionBox_Bottom_ValueChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(202, 506);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(35, 15);
            this.label4.TabIndex = 8;
            this.label4.Text = "Right";
            // 
            // txt_CollisionBox_Right
            // 
            this.txt_CollisionBox_Right.Location = new System.Drawing.Point(202, 523);
            this.txt_CollisionBox_Right.Maximum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.txt_CollisionBox_Right.Name = "txt_CollisionBox_Right";
            this.txt_CollisionBox_Right.Size = new System.Drawing.Size(59, 23);
            this.txt_CollisionBox_Right.TabIndex = 7;
            this.txt_CollisionBox_Right.ValueChanged += new System.EventHandler(this.txt_CollisionBox_Right_ValueChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(68, 506);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(26, 15);
            this.label2.TabIndex = 6;
            this.label2.Text = "Top";
            // 
            // txt_CollisionBox_Top
            // 
            this.txt_CollisionBox_Top.Location = new System.Drawing.Point(68, 523);
            this.txt_CollisionBox_Top.Maximum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.txt_CollisionBox_Top.Name = "txt_CollisionBox_Top";
            this.txt_CollisionBox_Top.Size = new System.Drawing.Size(59, 23);
            this.txt_CollisionBox_Top.TabIndex = 5;
            this.txt_CollisionBox_Top.ValueChanged += new System.EventHandler(this.txt_CollisionBox_Top_ValueChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 506);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(27, 15);
            this.label1.TabIndex = 4;
            this.label1.Text = "Left";
            // 
            // txt_CollisionBox_Left
            // 
            this.txt_CollisionBox_Left.Location = new System.Drawing.Point(3, 523);
            this.txt_CollisionBox_Left.Maximum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.txt_CollisionBox_Left.Name = "txt_CollisionBox_Left";
            this.txt_CollisionBox_Left.Size = new System.Drawing.Size(59, 23);
            this.txt_CollisionBox_Left.TabIndex = 3;
            this.txt_CollisionBox_Left.ValueChanged += new System.EventHandler(this.txt_CollisionBox_Left_ValueChanged);
            // 
            // txt_Collision
            // 
            this.txt_Collision.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_Collision.Location = new System.Drawing.Point(3, 548);
            this.txt_Collision.Name = "txt_Collision";
            this.txt_Collision.Size = new System.Drawing.Size(327, 23);
            this.txt_Collision.TabIndex = 2;
            // 
            // btn_AddCollision
            // 
            this.btn_AddCollision.Location = new System.Drawing.Point(6, 6);
            this.btn_AddCollision.Name = "btn_AddCollision";
            this.btn_AddCollision.Size = new System.Drawing.Size(75, 23);
            this.btn_AddCollision.TabIndex = 1;
            this.btn_AddCollision.Text = "Add Box";
            this.btn_AddCollision.UseVisualStyleBackColor = true;
            this.btn_AddCollision.Click += new System.EventHandler(this.btn_AddCollision_Click);
            // 
            // lst_Collision
            // 
            this.lst_Collision.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.lst_Collision.FormattingEnabled = true;
            this.lst_Collision.ItemHeight = 15;
            this.lst_Collision.Location = new System.Drawing.Point(3, 33);
            this.lst_Collision.Name = "lst_Collision";
            this.lst_Collision.Size = new System.Drawing.Size(327, 469);
            this.lst_Collision.TabIndex = 0;
            this.lst_Collision.SelectedIndexChanged += new System.EventHandler(this.lst_Collision_SelectedIndexChanged);
            // 
            // images
            // 
            this.images.ColorDepth = System.Windows.Forms.ColorDepth.Depth32Bit;
            this.images.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("images.ImageStream")));
            this.images.TransparentColor = System.Drawing.Color.Transparent;
            this.images.Images.SetKeyName(0, "cell_transparent.png");
            this.images.Images.SetKeyName(1, "cell_solid.png");
            this.images.Images.SetKeyName(2, "cell_active.png");
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1145, 631);
            this.Controls.Add(this.tabs);
            this.Controls.Add(this.scroll_Scene);
            this.Controls.Add(this.btn_Extract);
            this.Controls.Add(this.btn_Save);
            this.Controls.Add(this.pic_Cell);
            this.Controls.Add(this.txt_SceneName);
            this.Name = "Main";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Main_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pic_Scene)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_Cell)).EndInit();
            this.scroll_Scene.ResumeLayout(false);
            this.tabs.ResumeLayout(false);
            this.tab_palette.ResumeLayout(false);
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txt_CollisionBox_Bottom)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txt_CollisionBox_Right)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txt_CollisionBox_Top)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txt_CollisionBox_Left)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private PixelBox pic_Scene;
        private TextBox txt_SceneName;
        private PixelBox pic_Cell;
        private Button btn_Save;
        private TilePalette Palette;
        private Button btn_Extract;
        private ScrollPanel scroll_Scene;
        private TabControl tabs;
        private TabPage tab_palette;
        private TabPage tabPage2;
        private ListBox lst_Collision;
        private Button btn_AddCollision;
        private TextBox txt_Collision;
        private ImageList images;
        private Label label2;
        private NumericUpDown txt_CollisionBox_Top;
        private Label label1;
        private NumericUpDown txt_CollisionBox_Left;
        private Label label3;
        private NumericUpDown txt_CollisionBox_Bottom;
        private Label label4;
        private NumericUpDown txt_CollisionBox_Right;
    }
}