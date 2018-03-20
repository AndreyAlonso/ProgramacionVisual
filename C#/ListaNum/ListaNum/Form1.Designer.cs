namespace ListaNum
{
    partial class Form1
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.listaDeNúmerosToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.creaLista = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.imprimeListaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.imprimeComboToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.SystemColors.InactiveCaption;
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.listaDeNúmerosToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(284, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // listaDeNúmerosToolStripMenuItem
            // 
            this.listaDeNúmerosToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.creaLista,
            this.toolStripSeparator1,
            this.imprimeListaToolStripMenuItem,
            this.toolStripSeparator2,
            this.imprimeComboToolStripMenuItem});
            this.listaDeNúmerosToolStripMenuItem.Name = "listaDeNúmerosToolStripMenuItem";
            this.listaDeNúmerosToolStripMenuItem.Size = new System.Drawing.Size(111, 20);
            this.listaDeNúmerosToolStripMenuItem.Text = "Lista de Números";
            this.listaDeNúmerosToolStripMenuItem.DropDownItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.ListaNum_Click);
            // 
            // creaLista
            // 
            this.creaLista.AccessibleName = "creaLista";
            this.creaLista.Name = "creaLista";
            this.creaLista.Size = new System.Drawing.Size(162, 22);
            this.creaLista.Text = "Crea Lista";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(159, 6);
            // 
            // imprimeListaToolStripMenuItem
            // 
            this.imprimeListaToolStripMenuItem.AccessibleName = "imprimeLista";
            this.imprimeListaToolStripMenuItem.Name = "imprimeListaToolStripMenuItem";
            this.imprimeListaToolStripMenuItem.Size = new System.Drawing.Size(162, 22);
            this.imprimeListaToolStripMenuItem.Text = "Imprime Lista";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(159, 6);
            // 
            // imprimeComboToolStripMenuItem
            // 
            this.imprimeComboToolStripMenuItem.AccessibleName = "imprimeCombo";
            this.imprimeComboToolStripMenuItem.Name = "imprimeComboToolStripMenuItem";
            this.imprimeComboToolStripMenuItem.Size = new System.Drawing.Size(162, 22);
            this.imprimeComboToolStripMenuItem.Text = "Imprime Combo";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Paint);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem listaDeNúmerosToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem creaLista;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem imprimeListaToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem imprimeComboToolStripMenuItem;
    }
}

