using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mueve_Boton
{
    public partial class Form1 : Form
    {
        Button boton, boton2;
        Size size, size2;
        Random random;
        int opcion;
        Point p, p2;
        int vida, vida2;
        int dir;
        int x;
        int tamB;
        int y;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dir = 0;
            size = new Size(100, 60);
            p = new Point(150, 150);
            boton = new Button();
            tamB = boton.Width;
            boton.Name = "b1";
            boton.Text = "Acción";
            boton.Size = size;
            boton.Location = p;
            boton.Visible = true;
            this.Controls.Add(boton);



        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            switch(dir){
                case 0:
                    p.X++;
                    p.Y--;
                    if (p.X <= this.ClientRectangle.Right - size.Width)
                    {
                        boton.Location = new Point(p.X, p.Y);
                    }
                    else
                    {
                        dir = 3;
                    }
                    if (p.Y >= this.ClientRectangle.Top)
                        boton.Location = new Point(p.X, p.Y);
                    else
                    {

                        dir = 1;
                    }

                break;
                case 1:
                    p.X++;
                    p.Y++;
                    if (p.X <= this.ClientRectangle.Right-tamB)
                        boton.Location = new Point(p.X, p.Y);
                    else
                    {

                        dir = 0;
                    }
                    if(p.Y <= this.ClientRectangle.Top )
                        boton.Location = new Point(p.X, p.Y);
                    else
                    {
                        dir = 2;
                    }
                break;
                case 2:
                    p.X--;
                    p.Y++;
                    if(p.X >= this.ClientRectangle.Left)
                        boton.Location = new Point(p.X, p.Y);
                    else
                    {
                        dir = 1;
                    }
                    if (p.Y < this.ClientRectangle.Bottom)
                    {
                        boton.Location = new Point(p.X, p.Y);
                    }
                    else
                    {
                        dir = 3;
                    }

                break;
                case 3:
                    p.X--;
                    p.Y--;
                    if (p.X >= this.ClientRectangle.Left)
                    {
                        boton.Location = new Point(p.X, p.Y);
                    }
                    else
                    {
                        dir = 0;
                    }
                    if (p.Y >= this.ClientRectangle.Top)
                    {
                        boton.Location = new Point(p.X, p.Y);
                    }
                    else
                    {
                        dir = 2;
                    }
                break;
                
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Start();
            timer1.Interval = 2;
            button1.Visible = false;
        }
            /***************************
            button1.Hide();
            boton = new Button();
            boton2 = new Button();

            p = new Point(20, 20);
            p2 = new Point(20, 20);

            size = new Size(20, 20);
            size2 = new Size(20, 20);
            vida = 100;
            boton2.Text = vida.ToString();
            boton.Text = vida.ToString();
            boton.Location = p;
            boton2.Location = p2;
            this.Controls.Add(boton);
            this.Controls.Add(boton2);
            boton.Show();
            random = new Random();
            timer1.Interval = 100;
            timer1.Start();
            timer1.Enabled = true;
            boton.Visible = true;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {

            if (vida >= 0)
            {
                boton.Text = vida.ToString();
                opcion  = random.Next(1, 4);
                switch(opcion)
                {
                    case 1:
                        if(p.X < this.ClientRectangle.Right && p.Y < this.ClientRectangle.Bottom)
                        {
                            x++;
                            y++;
                        }
                    break;
                    case 2:
                        if(p.X < this.ClientRectangle.Right && p.Y > this.ClientRectangle.Bottom)
                        {
                            x++;
                            y--;
                        }
                    break;
                    case 3:
                        if(p.X > this.ClientRectangle.Right && p.Y < this.ClientRectangle.Bottom)
                        x--;
                        y++;
                    break;
                        case 4:
                        if (p.X > this.ClientRectangle.Right && p.Y > this.ClientRectangle.Bottom)
                        {
                            x--;
                            y--;
                        }
                    break;
                }
                p.X = x;
                p.Y = y;
                boton.Location = p;
                boton2.Location = p;
                boton2.Update();
                boton.Update();
                vida--;
                
                
               
            }
            if (vida == 0)
            {
                boton.Dispose();
            }
        }* *****************/
        }

        

    
}
