namespace Interface
{
    partial class StartForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(StartForm));
            this.NameOfTransl = new System.Windows.Forms.Label();
            this.CodeInFile = new System.Windows.Forms.TextBox();
            this.labelExit = new System.Windows.Forms.Label();
            this.iconGitHub = new System.Windows.Forms.PictureBox();
            this.iconVK = new System.Windows.Forms.PictureBox();
            this.iconInst = new System.Windows.Forms.PictureBox();
            this.menu = new System.Windows.Forms.ToolStripMenuItem();
            this.sdfsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dfdfToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.sdToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.sdToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.menuTXTMain = new System.Windows.Forms.MenuStrip();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.compile = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.iconGitHub)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.iconVK)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.iconInst)).BeginInit();
            this.menuTXTMain.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // NameOfTransl
            // 
            this.NameOfTransl.Font = new System.Drawing.Font("Showcard Gothic", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.NameOfTransl.Location = new System.Drawing.Point(-16, 9);
            this.NameOfTransl.Name = "NameOfTransl";
            this.NameOfTransl.Size = new System.Drawing.Size(409, 71);
            this.NameOfTransl.TabIndex = 1;
            this.NameOfTransl.Text = "KAD 2022 - POIT_5";
            this.NameOfTransl.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.NameOfTransl.MouseDown += new System.Windows.Forms.MouseEventHandler(this.NameOfTransl_MouseDown);
            this.NameOfTransl.MouseMove += new System.Windows.Forms.MouseEventHandler(this.NameOfTransl_MouseMove);
            // 
            // CodeInFile
            // 
            this.CodeInFile.BackColor = System.Drawing.SystemColors.WindowFrame;
            this.CodeInFile.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.CodeInFile.Font = new System.Drawing.Font("Consolas", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.CodeInFile.Location = new System.Drawing.Point(12, 75);
            this.CodeInFile.Multiline = true;
            this.CodeInFile.Name = "CodeInFile";
            this.CodeInFile.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.CodeInFile.Size = new System.Drawing.Size(780, 545);
            this.CodeInFile.TabIndex = 3;
            // 
            // labelExit
            // 
            this.labelExit.AutoSize = true;
            this.labelExit.Cursor = System.Windows.Forms.Cursors.Hand;
            this.labelExit.Font = new System.Drawing.Font("Showcard Gothic", 12F, System.Drawing.FontStyle.Bold);
            this.labelExit.Location = new System.Drawing.Point(774, -3);
            this.labelExit.Name = "labelExit";
            this.labelExit.Size = new System.Drawing.Size(32, 30);
            this.labelExit.TabIndex = 4;
            this.labelExit.Text = "x";
            this.labelExit.Click += new System.EventHandler(this.labelExit_Click);
            this.labelExit.MouseEnter += new System.EventHandler(this.labelExit_MouseEnter);
            this.labelExit.MouseLeave += new System.EventHandler(this.labelExit_MouseLeave);
            // 
            // iconGitHub
            // 
            this.iconGitHub.Cursor = System.Windows.Forms.Cursors.Hand;
            this.iconGitHub.Image = ((System.Drawing.Image)(resources.GetObject("iconGitHub.Image")));
            this.iconGitHub.Location = new System.Drawing.Point(728, 649);
            this.iconGitHub.Name = "iconGitHub";
            this.iconGitHub.Size = new System.Drawing.Size(65, 64);
            this.iconGitHub.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.iconGitHub.TabIndex = 7;
            this.iconGitHub.TabStop = false;
            this.iconGitHub.Click += new System.EventHandler(this.iconGitHub_Click);
            // 
            // iconVK
            // 
            this.iconVK.Cursor = System.Windows.Forms.Cursors.Hand;
            this.iconVK.Image = ((System.Drawing.Image)(resources.GetObject("iconVK.Image")));
            this.iconVK.Location = new System.Drawing.Point(648, 649);
            this.iconVK.Name = "iconVK";
            this.iconVK.Size = new System.Drawing.Size(65, 64);
            this.iconVK.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.iconVK.TabIndex = 6;
            this.iconVK.TabStop = false;
            this.iconVK.Click += new System.EventHandler(this.iconVK_Click);
            // 
            // iconInst
            // 
            this.iconInst.Cursor = System.Windows.Forms.Cursors.Hand;
            this.iconInst.Image = ((System.Drawing.Image)(resources.GetObject("iconInst.Image")));
            this.iconInst.Location = new System.Drawing.Point(567, 649);
            this.iconInst.Name = "iconInst";
            this.iconInst.Size = new System.Drawing.Size(65, 64);
            this.iconInst.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.iconInst.TabIndex = 5;
            this.iconInst.TabStop = false;
            this.iconInst.Click += new System.EventHandler(this.iconInst_Click);
            // 
            // menu
            // 
            this.menu.AutoSize = false;
            this.menu.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.menu.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.menu.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.sdfsToolStripMenuItem,
            this.dfdfToolStripMenuItem,
            this.sdToolStripMenuItem,
            this.sdToolStripMenuItem1});
            this.menu.Font = new System.Drawing.Font("Showcard Gothic", 9F);
            this.menu.Image = ((System.Drawing.Image)(resources.GetObject("menu.Image")));
            this.menu.ImageTransparentColor = System.Drawing.Color.Transparent;
            this.menu.Name = "menu";
            this.menu.Size = new System.Drawing.Size(45, 40);
            this.menu.Text = "Work with txt-files";
            // 
            // sdfsToolStripMenuItem
            // 
            this.sdfsToolStripMenuItem.Font = new System.Drawing.Font("Showcard Gothic", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.sdfsToolStripMenuItem.Name = "sdfsToolStripMenuItem";
            this.sdfsToolStripMenuItem.Size = new System.Drawing.Size(248, 34);
            this.sdfsToolStripMenuItem.Text = "Open txt-file";
            this.sdfsToolStripMenuItem.Click += new System.EventHandler(this.sdfsToolStripMenuItem_Click);
            // 
            // dfdfToolStripMenuItem
            // 
            this.dfdfToolStripMenuItem.Font = new System.Drawing.Font("Showcard Gothic", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dfdfToolStripMenuItem.Name = "dfdfToolStripMenuItem";
            this.dfdfToolStripMenuItem.Size = new System.Drawing.Size(248, 34);
            this.dfdfToolStripMenuItem.Text = "Open LOG-file";
            this.dfdfToolStripMenuItem.Click += new System.EventHandler(this.dfdfToolStripMenuItem_Click);
            // 
            // sdToolStripMenuItem
            // 
            this.sdToolStripMenuItem.Font = new System.Drawing.Font("Showcard Gothic", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.sdToolStripMenuItem.Name = "sdToolStripMenuItem";
            this.sdToolStripMenuItem.Size = new System.Drawing.Size(248, 34);
            this.sdToolStripMenuItem.Text = "Open lexTable";
            this.sdToolStripMenuItem.Click += new System.EventHandler(this.sdToolStripMenuItem_Click);
            // 
            // sdToolStripMenuItem1
            // 
            this.sdToolStripMenuItem1.Font = new System.Drawing.Font("Showcard Gothic", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.sdToolStripMenuItem1.Name = "sdToolStripMenuItem1";
            this.sdToolStripMenuItem1.Size = new System.Drawing.Size(248, 34);
            this.sdToolStripMenuItem1.Text = "Open idTable";
            this.sdToolStripMenuItem1.Click += new System.EventHandler(this.sdToolStripMenuItem1_Click);
            // 
            // menuTXTMain
            // 
            this.menuTXTMain.BackColor = System.Drawing.Color.Transparent;
            this.menuTXTMain.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.menuTXTMain.Dock = System.Windows.Forms.DockStyle.None;
            this.menuTXTMain.Font = new System.Drawing.Font("Showcard Gothic", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.menuTXTMain.ImageScalingSize = new System.Drawing.Size(50, 50);
            this.menuTXTMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menu});
            this.menuTXTMain.Location = new System.Drawing.Point(16, 649);
            this.menuTXTMain.Name = "menuTXTMain";
            this.menuTXTMain.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
            this.menuTXTMain.Size = new System.Drawing.Size(53, 44);
            this.menuTXTMain.TabIndex = 9;
            this.menuTXTMain.Text = "menuStrip1";
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.Color.Transparent;
            this.menuStrip1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.menuStrip1.Dock = System.Windows.Forms.DockStyle.None;
            this.menuStrip1.Font = new System.Drawing.Font("Showcard Gothic", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(50, 50);
            this.menuStrip1.Location = new System.Drawing.Point(87, 649);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
            this.menuStrip1.Size = new System.Drawing.Size(202, 24);
            this.menuStrip1.TabIndex = 10;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // compile
            // 
            this.compile.Cursor = System.Windows.Forms.Cursors.Hand;
            this.compile.FlatAppearance.BorderSize = 2;
            this.compile.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.compile.Font = new System.Drawing.Font("Showcard Gothic", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.compile.Location = new System.Drawing.Point(87, 649);
            this.compile.Name = "compile";
            this.compile.Size = new System.Drawing.Size(223, 64);
            this.compile.TabIndex = 11;
            this.compile.Text = "compile ";
            this.compile.UseVisualStyleBackColor = true;
            this.compile.Click += new System.EventHandler(this.compile_Click_1);
            // 
            // button1
            // 
            this.button1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button1.FlatAppearance.BorderSize = 2;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Font = new System.Drawing.Font("Showcard Gothic", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(326, 649);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(223, 64);
            this.button1.TabIndex = 12;
            this.button1.Text = "Compile ASM";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(717, 31);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(42, 38);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 13;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // StartForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LightGray;
            this.ClientSize = new System.Drawing.Size(804, 727);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.compile);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.iconGitHub);
            this.Controls.Add(this.iconVK);
            this.Controls.Add(this.iconInst);
            this.Controls.Add(this.labelExit);
            this.Controls.Add(this.CodeInFile);
            this.Controls.Add(this.NameOfTransl);
            this.Controls.Add(this.menuTXTMain);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuTXTMain;
            this.Name = "StartForm";
            this.Text = "StartForm";
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.StartForm_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.StartForm_MouseMove);
            ((System.ComponentModel.ISupportInitialize)(this.iconGitHub)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.iconVK)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.iconInst)).EndInit();
            this.menuTXTMain.ResumeLayout(false);
            this.menuTXTMain.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label NameOfTransl;
        private System.Windows.Forms.TextBox CodeInFile;
        private System.Windows.Forms.Label labelExit;
        private System.Windows.Forms.PictureBox iconGitHub;
        private System.Windows.Forms.PictureBox iconVK;
        private System.Windows.Forms.PictureBox iconInst;
        private System.Windows.Forms.ToolStripMenuItem menu;
        private System.Windows.Forms.ToolStripMenuItem sdfsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dfdfToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem sdToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem sdToolStripMenuItem1;
        private System.Windows.Forms.MenuStrip menuTXTMain;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.Button compile;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.PictureBox pictureBox1;
    }
}