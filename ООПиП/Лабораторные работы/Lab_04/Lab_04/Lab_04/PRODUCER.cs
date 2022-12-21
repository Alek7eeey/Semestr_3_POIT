using LAB_4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace Lab_04
{
    public class PRODUCER : INFORMATION
    {
        public string? _name;
        public virtual void name(string name)
        {
            Console.WriteLine("Имя: {0}", name);
            this._name = name;
        }

        public string _age;
        public virtual string age(string age)
        {
            Console.WriteLine("Возраст: {0}", age);
            this._age = age;
            return age;
        }

        public string _country;
        public virtual void country(string country)
        {
            Console.WriteLine("Страна: {0}", country);
            this._country = country;
        }

        public PRODUCER(string? name, string age, string country)
        {
            _name = name;
            _age = age;
            _country = country;
        }

        public override string ToString()
        {
            Console.WriteLine("Информация про режиссера: ");
            Console.WriteLine("Имя: {0}", _name );
            Console.WriteLine("Страна: {0}", _country);
            Console.WriteLine("Возраст {0}", _age);
            return "";
        }
    }
}
