using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DelegadoAlumnos
{
    class Alumno
    {
        private string nombre;
        public string Nombre { get { return nombre; } set { nombre = value; } }

        private int edad;
        public int Edad { get { return edad; } }
        
        private Button boton;
        public Button Boton { get { return boton; } }
        public Alumno(string _nombre, int _edad, Point localizacion)
        {
            this.edad = _edad;
            this.nombre = _nombre;
            boton = new Button();

            boton.Size = new System.Drawing.Size(100, 50);
            boton.Location = localizacion;
            boton.Text = this.nombre;
            boton.Click += boton_Click;

        }
        void boton_Click(object sender, EventArgs e)
        {
            MessageBox.Show(boton.Text);
        }
        public override string ToString()
        {
            return "Edad: " + this.edad.ToString() + "      Nombre: " + this.nombre;
        }

    }
}
