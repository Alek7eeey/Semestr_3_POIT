using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_04
{
    sealed public class MAIN_CHARACTER: PRODUCER
    {
        public string? _name;
        public void name(string name)
        {
            Console.WriteLine("Имя: {0}", name);
            this._name = name;
        }

        public string _age;
        public string age(string age)
        {
            Console.WriteLine("Возраст: {0}", age);
            this._age = age;
            return age;
        }

        public string _country;

        public MAIN_CHARACTER(string? name, string age, string country) : base (name, age, country)
        {
            _name = name;
            _age = age;
            _country = country;
        }

        public void country(string country)
        {
            Console.WriteLine("Страна: {0}", country);
            this._country = country;
        }

        public override string ToString()
        {
            Console.WriteLine("Информация про главного героя: ");
            Console.WriteLine("Имя: {0}", _name);
            Console.WriteLine("Страна: {0}", _country);
            Console.WriteLine("Возраст {0}", _age);
            return "";
        }
    }
}
