using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Figuras
{
    public partial class Form1 : Form
    {
        Point p1, p2;
        Graphics g;
        Pen pen;
        int opcionFigura;
        int ancho, alto;
        Color color;
        AdjustableArrowCap flecha;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            g = CreateGraphics();
            pen = new Pen(Color.Blue);
            pen.Width = 0;
            opcionFigura = 0;
            ancho = alto = 0;
            flecha = new AdjustableArrowCap(10, 10);

        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            p1 = e.Location;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            alto   = Math.Abs(p2.Y - p1.Y);
            ancho  = Math.Abs(p2.X - p1.X);
            switch (opcionFigura)
            {
                case 1:
                    g.DrawRectangle(pen, p1.X, p1.Y, ancho, alto);
                break;
                case 2:
                    g.DrawEllipse(pen, p1.X, p2.Y,ancho, alto);
                break;
                case 3:
                    pen.CustomEndCap = flecha;  
                  //  pen.EndCap = System.Drawing.Drawing2D.LineCap.ArrowAnchor;
                    g.DrawLine(pen, p1, p2);
                break;
            }    
        }
        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            p2 = e.Location;
            Form1_Paint(this, null);
        }

        

        private void shapesToolStripMenuItem_DropDownItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            switch(e.ClickedItem.AccessibleName)
            {
                case "rectangle":
                    opcionFigura = 1;
                    toolStripTextBox1.Text = "Rectangle";
                break;
                case "ellipse":
                    opcionFigura = 2;
                    toolStripTextBox1.Text = "Ellipse";
              
                break;
                case "line":
                    opcionFigura = 3;
                    toolStripTextBox1.Text = "Line";
                break;
            }
        }

        private void colorsToolStripMenuItem_DropDownItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            switch (e.ClickedItem.AccessibleName)
            {
                case "Red":
                  
                    color = Color.Red;
                    pen.Color = color;
                break;
                case "Green":
                  
                    color = Color.Green;
                    pen.Color = color;
                break;
                case "Blue":
               
                    color = Color.Blue;
                    pen.Color = color;
                break;

            }
        }

        private void witdthLineToolStripMenuItem_DropDownItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            switch(e.ClickedItem.AccessibleName)
            {
                case "1":
                    pen.Width = 1;
                break;
                case "2":
                pen.Width = 2;
                break;
                case "3":
                pen.Width = 3;
                break;
                case "4":
                pen.Width = 4;
                break;
                case "5":
                pen.Width = 5;
                break;
            }
        }

        private void witdthLineToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void clearWindowToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Invalidate();
  
        }
    }
}
