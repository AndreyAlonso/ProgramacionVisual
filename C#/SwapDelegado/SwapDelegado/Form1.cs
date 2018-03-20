using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SwapDelegado
{
    public partial class Form1 : Form
    {
        int a, b;
        intercambio s;
        delegate void intercambio(ref int a, ref int b);
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = Convert.ToString(10);
            textBox2.Text = Convert.ToString(20);
            s = new intercambio(Swap);
           
        }
        public void Swap(ref int x,ref int y)
        {
            int aux;
            x = Convert.ToInt32(textBox1.Text);
            y = Convert.ToInt32(textBox2.Text);
            aux = x;
            x = y;
            y = aux;

        }
        private void button1_Click(object sender, EventArgs e)
        {
            s(ref a,ref b);
            textBox1.Text = a.ToString();
            textBox2.Text = b.ToString();
        }
    }
}
