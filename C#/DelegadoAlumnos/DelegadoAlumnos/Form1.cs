using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DelegadoAlumnos
{
    public partial class Form1 : Form
    {
        List<Alumno> listaAlumno;
        Alumno alumno;
        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.listaAlumno = new List<Alumno>();

            alumno = new Alumno("Andrey", 20, new Point(100, 80));
            this.Controls.Add(alumno.Boton);
            alumno.Boton.Click += Boton_Click;
            this.listaAlumno.Add(alumno);

            alumno = new Alumno("Oscar", 21, new Point(300, 80));
            this.Controls.Add(alumno.Boton);
            alumno.Boton.Click += Boton_Click;
            this.listaAlumno.Add(alumno);

            alumno = new Alumno("Braulio", 22, new Point(100, 180));
            this.Controls.Add(alumno.Boton);
            alumno.Boton.Click += Boton_Click;
            this.listaAlumno.Add(alumno);

            alumno = new Alumno("Luis", 17, new Point(300, 180));
            this.Controls.Add(alumno.Boton);
            alumno.Boton.Click += Boton_Click;
            this.listaAlumno.Add(alumno);
           
            
        }

        private void Boton_Click(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
            MessageBox.Show((sender as Button).Text + " Forma");
        }
        private void llenaCombo(List<Alumno> lista)
        {
            BindingSource bindingSource;
            bindingSource = new BindingSource();

            bindingSource.DataSource = lista;
            comboAlumno.DataSource = lista;
            comboAlumno.DataSource = null;
            comboAlumno.Items.Clear();
            comboAlumno.DataSource = bindingSource.DataSource;
        }

        private void SortDelegadosEdad_Click(object sender, EventArgs e){
            this.listaAlumno.Sort( delegate(Alumno x, Alumno y) { return x.Edad.CompareTo(y.Edad); } );
            this.llenaCombo(listaAlumno);
        }
        private void SortDelegadosNombre_Click(object sender, EventArgs e)
        {
            this.listaAlumno.Sort(delegate(Alumno x, Alumno y) { return x.Nombre.CompareTo(y.Nombre); });
            this.llenaCombo(listaAlumno);
        }

        private void nombreToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SortDelegadosNombre_Click(sender, e);
        }

        private void edadToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SortDelegadosEdad_Click(sender, e);
        }

       
    }
}
