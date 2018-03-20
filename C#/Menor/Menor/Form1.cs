using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Menor
{
    public partial class Form1 : Form
    {
        int menor;
        int[] arr = { 6, 3, 8, 2, 4 };
        delegate int Compara();
        Compara s;
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            this.Text = "Núumero menor";
            menor = 1000;
            textBox1.Text = menor.ToString();
            s = new Compara(Menor);
        }
        public int Menor()
        {
            foreach (int i in arr)
            {
                if (menor > i)
                {
                    menor = i;
                    textBox1.Text = menor.ToString();
                }
            }
            return menor;
        }
        private void button1_Click_1(object sender, EventArgs e)
        {
           // s();
            textBox1.Text = s().ToString() +"!!!";
        }
    }
}
