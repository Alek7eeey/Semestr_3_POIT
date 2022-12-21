using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using System.Runtime.Remoting.Messaging;
using System.Diagnostics;
using System.Threading;

namespace Interface
{
    public partial class StartForm : Form
    {
        public StartForm()
        {
            InitializeComponent();
            KeyPreview = true;
        }

        private void labelExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void labelExit_MouseEnter(object sender, EventArgs e)
        {
            labelExit.ForeColor = Color.FromArgb(84, 84, 84);
        }

        private void labelExit_MouseLeave(object sender, EventArgs e)
        {
            labelExit.ForeColor = Color.Black;
        }

        Point lastPoint;
        private void StartForm_MouseMove(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void StartForm_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void NameOfTransl_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void NameOfTransl_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void iconInst_Click(object sender, EventArgs e)
        {
            string path = "https://www.instagram.com/kravchenko__aleksey/";
            MessageBox.Show(path, "Instagram");
        }

        private void iconVK_Click(object sender, EventArgs e)
        {
            string path = "https://vk.com/kravchenkoaleksey";
            MessageBox.Show(path,"VK");
        }

        private void iconGitHub_Click(object sender, EventArgs e)
        {
            string path = "https://github.com/Alek7eeey";
            MessageBox.Show(path, "GitHub");
        }

        private void sdfsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string fileText = "";
            fileText += System.IO.File.ReadAllText("D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Курсовой_проект\\KAD-2022\\Debug\\Files\\in.txt", System.Text.Encoding.Default);
            CodeInFile.Text = fileText;
        }

        private void dfdfToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string fileText = "";
            fileText += System.IO.File.ReadAllText("D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Курсовой_проект\\KAD-2022\\Debug\\Files\\in.txt.log", System.Text.Encoding.Default);
            CodeInFile.Text = fileText;
        }

        private void sdToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string fileText = "";
            fileText += System.IO.File.ReadAllText("D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Курсовой_проект\\KAD-2022\\Debug\\Files\\Table.lex.txt", System.Text.Encoding.Default);
            CodeInFile.Text = fileText;
        }

        private void sdToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            string fileText = "";
            fileText += System.IO.File.ReadAllText("D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Курсовой_проект\\KAD-2022\\Debug\\Files\\Table.id.txt", System.Text.Encoding.Default);
            CodeInFile.Text = fileText;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Process p = new Process();
            p.StartInfo.UseShellExecute = true;
            p.StartInfo.FileName = "cmd.exe";
            p.StartInfo.Arguments = "/k" + "cd C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Visual Studio 2022\\Visual Studio Tools & Dev.lnk & " +
                "cd D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Курсовой_проект\\KAD-2022\\Debug\\Files & ml /c /coff in.txt.asm &" +
                "link /OPT:NOREF /DEBUG in.txt.obj StaticLib.lib /SUBSYSTEM:CONSOLE & cd D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Курсовой_проект\\KAD-2022\\Debug & ASM.exe";
            p.StartInfo.CreateNoWindow = true;
            p.Start();
            p.WaitForExit();

        }

        private void compile_Click_1(object sender, EventArgs e)
        {
            if (CodeInFile.Text.Count()!=0)
            {
                StreamWriter f = new StreamWriter("D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Курсовой_проект\\KAD-2022\\Debug\\Files\\in.txt", false, System.Text.Encoding.Default);
                StreamWriter f2 = new StreamWriter("D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Курсовой_проект\\KAD-2022\\KAD-2022\\Files\\in.txt", false, System.Text.Encoding.Default);
                using (StreamWriter str = f, str2 = f2)
                {
                    str.WriteLine(CodeInFile.Text);
                    str2.WriteLine(CodeInFile.Text);
                    str.Close();
                    str2.Close();
                }

                Process p = new Process();
                p.StartInfo.UseShellExecute = true;
                p.StartInfo.FileName = "cmd.exe";
                p.StartInfo.Arguments = "/k" + "cd D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Курсовой_проект\\KAD-2022\\Debug & KAD-2022.exe -in:Files\\in.txt";
                p.StartInfo.CreateNoWindow = true;
                p.Start();
                p.WaitForExit();
            }

            else
            {
                MessageBox.Show("Вы пытаетесь скомпилировать пустой файл!", "Ошибка");
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            CodeInFile.Text= null;
        }
    }
}
