﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PrimeroCS
{
    public partial class Form1 : Form
    {
        string cad;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = "Hola";
            textBox2.Text = "Mundo";
        }

        private void Accion_Click(object sender, EventArgs e)
        {
            cad  = textBox1.Text;
            textBox1.Text = textBox2.Text;
            textBox2.Text = cad;
         
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
