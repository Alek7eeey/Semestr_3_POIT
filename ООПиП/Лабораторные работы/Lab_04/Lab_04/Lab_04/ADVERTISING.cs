using LAB_4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_04
{
    public class ADVERTISING:TV_program, INFORMATION
    {
        public string StartTIME;
        public override void start_time(string time)
        {
            Console.WriteLine("Время начала: {0}", time);
            this.StartTIME = time;
        }
        public string _duraTION;
        public override void duration(string dur)
        {
            Console.WriteLine("Длительность: {0}", dur);
            this._duraTION = dur;
        }
        public string _ageRestrictions;
        public override void age_restrictions(string age)
        {
            Console.WriteLine("Возрастное ограничение: {0}", age);
            this._ageRestrictions = age;
        }
        public string _country;
        public override void country(string country)
        {
            Console.WriteLine("Страна: {0}", country);
            this._country = country;
        }

        public ADVERTISING(string startTIME, string duraTION, string ageRestrictions, string country, string name)
        {
            StartTIME = startTIME;
            _duraTION = duraTION;
            _ageRestrictions = ageRestrictions;
            _country = country;
            _name = name;
        }




        //----------------------------------------------//
        public string _name;
        public void name(string name)
        {
            Console.WriteLine("Имя: {0}", name);
            this._name = name;
        }
        public string age(string age)
        {
            Console.WriteLine("Возраст: {0}", age);
            return age;
        }

        void INFORMATION.country(string country)
        {
            Console.WriteLine("Страна: {0}", country);
        }

        public override string ToString()
        {
            Console.WriteLine("Информация про рекламу: ");
            Console.WriteLine("Время начала: {0}", StartTIME);
            Console.WriteLine("Длительность: {0}", _duraTION);
            Console.WriteLine("Возрастные ограничения: {0}", _ageRestrictions);
            Console.WriteLine("Страна: {0}", _country);
            Console.WriteLine("Имя режиссера: {0}",_name);
            return "";
        }
    }
}
