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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Main));
            this.pic_Scene = new keshiki.Controls.PixelBox();
            this.txt_SceneName = new System.Windows.Forms.TextBox();
            this.pic_Cell = new keshiki.Controls.PixelBox();
            this.btn_Save = new System.Windows.Forms.Button();
            this.Palette = new keshiki.Controls.TilePalette();
            this.btn_Extract = new System.Windows.Forms.Button();
            this.scroll_Scene = new keshiki.Controls.ScrollPanel();
            ((System.ComponentModel.ISupportInitialize)(this.pic_Scene)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_Cell)).BeginInit();
            this.scroll_Scene.SuspendLayout();
            this.SuspendLayout();
            // 
            // pic_Scene
            // 
            this.pic_Scene.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.NearestNeighbor;
            this.pic_Scene.Location = new System.Drawing.Point(3, 3);
            this.pic_Scene.Name = "pic_Scene";
            this.pic_Scene.Size = new System.Drawing.Size(536, 382);
            this.pic_Scene.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pic_Scene.TabIndex = 0;
            this.pic_Scene.TabStop = false;
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
            this.pic_Cell.Image = ((System.Drawing.Image)(resources.GetObject("pic_Cell.Image")));
            this.pic_Cell.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.NearestNeighbor;
            this.pic_Cell.Location = new System.Drawing.Point(783, 27);
            this.pic_Cell.Name = "pic_Cell";
            this.pic_Cell.Size = new System.Drawing.Size(48, 48);
            this.pic_Cell.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pic_Cell.TabIndex = 3;
            this.pic_Cell.TabStop = false;
            this.pic_Cell.Click += new System.EventHandler(this.pic_Cell_Click);
            // 
            // btn_Save
            // 
            this.btn_Save.Location = new System.Drawing.Point(1036, 2);
            this.btn_Save.Name = "btn_Save";
            this.btn_Save.Size = new System.Drawing.Size(88, 26);
            this.btn_Save.TabIndex = 4;
            this.btn_Save.Text = "Save";
            this.btn_Save.UseVisualStyleBackColor = true;
            this.btn_Save.Click += new System.EventHandler(this.btn_Save_Click);
            // 
            // Palette
            // 
            this.Palette.AutoScroll = true;
            this.Palette.Columns = 6;
            this.Palette.Location = new System.Drawing.Point(783, 27);
            this.Palette.Name = "Palette";
            this.Palette.SelectedTile = null;
            this.Palette.Size = new System.Drawing.Size(341, 480);
            this.Palette.TabIndex = 5;
            // 
            // btn_Extract
            // 
            this.btn_Extract.Location = new System.Drawing.Point(942, 2);
            this.btn_Extract.Name = "btn_Extract";
            this.btn_Extract.Size = new System.Drawing.Size(88, 26);
            this.btn_Extract.TabIndex = 6;
            this.btn_Extract.Text = "Extract";
            this.btn_Extract.UseVisualStyleBackColor = true;
            this.btn_Extract.Click += new System.EventHandler(this.btn_Extract_Click);
            // 
            // scroll_Scene
            // 
            this.scroll_Scene.AutoScroll = true;
            this.scroll_Scene.Controls.Add(this.pic_Scene);
            this.scroll_Scene.Location = new System.Drawing.Point(0, 26);
            this.scroll_Scene.Name = "scroll_Scene";
            this.scroll_Scene.Size = new System.Drawing.Size(777, 481);
            this.scroll_Scene.TabIndex = 7;
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1125, 508);
            this.Controls.Add(this.scroll_Scene);
            this.Controls.Add(this.btn_Extract);
            this.Controls.Add(this.Palette);
            this.Controls.Add(this.btn_Save);
            this.Controls.Add(this.pic_Cell);
            this.Controls.Add(this.txt_SceneName);
            this.Name = "Main";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Main_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pic_Scene)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic_Cell)).EndInit();
            this.scroll_Scene.ResumeLayout(false);
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
    }
}