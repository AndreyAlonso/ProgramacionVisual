using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Accion_Boton
{
    public partial class Form1 : Form
    {
        Button boton;
        Size size;
        Point pt;
      
        public Form1()
        {
            InitializeComponent();

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            boton = new Button();
            size  = new Size(100, 60);
            pt    = new Point(90, 150);

            this.Controls.Add(boton);
            boton.Click += boton_Click;
            boton.Visible = true;
            boton.Name = "Acción";
            boton.Text = "Accion";
            boton.Size = size;
            boton.Location = pt;

            boton.Show();
        
            
        }

        void boton_Click(object sender, EventArgs e)
        {
            textBox1.Text = "Success!!!";
        }
    }
}
