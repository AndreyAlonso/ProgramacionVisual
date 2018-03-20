using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ListaNum
{
    public partial class Form1 : Form
    {
        private int numero, nums, x;
        private Random r;
        private Numero n;
        private Graphics g;
        private bool band;
      
     
        
        List<Numero> lista;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            lista = new List<Numero>();
            r  = new Random();
            g = CreateGraphics();
            nums = 0;
            band = false;
            x = 10;


        }

        private void ListaNum_Click(object sender, ToolStripItemClickedEventArgs e)
        {
            switch(e.ClickedItem.AccessibleName)
            {
                case "creaLista":
                    nums = r.Next(3, 5);
                    while(nums != 0)
                    {
                        numero = r.Next(20);
                        n = new Numero();
                        n.num = numero;
                        lista.Add(n);  
                    }
                break;
                case "imprimeLista":
                    band = true;
                    Paint(this, null);
                break;
                case "imprimeCombo":
                break;
            }
        }

        private void Paint(object sender, PaintEventArgs e)
        {
           String cad = "";
            if(band)
            {
                foreach (Numero n in lista)
                {
                    cad = n.num.ToString();
                    g.DrawString(cad, new Font("Arial", 10), new SolidBrush(Color.Blue), new Point(x+=20,100));

                }

            }
            
        }
        

       
    }
}
