using LAB_4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_04
{
    public class ART_FILMS:TV_program
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

        public ART_FILMS(string startTIME, string duraTION, string ageRestrictions, string country)
        {
            StartTIME = startTIME;
            _duraTION = duraTION;
            _ageRestrictions = ageRestrictions;
            _country = country;
        }



        //ПЕРЕОПРЕДЕЛНИЕ БАЗОВОГО КЛАССА
        public override string ToString()
        {
            Console.WriteLine("Информация про художественные фильмы: ");
            Console.WriteLine("Время начала: {0}", StartTIME);
            Console.WriteLine("Длительность: {0}", _duraTION);
            Console.WriteLine("Возрастные ограничения: {0}", _ageRestrictions);
            Console.WriteLine("Страна: {0}", _country);
            return "";
        }

        public string Information_about_ART_FILMS { get; set; } = "";

        public override int GetHashCode()
        {
            return Information_about_ART_FILMS.GetHashCode();
        }

        //GetType не переопределяется

        public string Name { get; set; } = "";
        public override bool Equals(object? obj)
        {
            // если параметр метода представляет тип Person
            // то возвращаем true, если имена совпадают
            if (obj is ART_FILMS person) return Name == person.Name;
            return false;
        }
    }
}
