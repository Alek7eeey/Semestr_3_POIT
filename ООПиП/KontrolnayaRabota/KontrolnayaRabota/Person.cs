using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KontrolnayaRabota
{
    public class Person
    {
        int year;
        string name;
        public Person(int _year, string _name)
        {
            this.year = _year;
            this.name = _name;
        }
        public override string ToString()
        {
            Console.WriteLine("Имя: " + name);
            Console.WriteLine("Дата рождения: "+year);
            return "";
        }
    }
}
