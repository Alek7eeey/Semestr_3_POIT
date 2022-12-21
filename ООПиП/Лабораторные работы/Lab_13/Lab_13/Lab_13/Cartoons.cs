using System;
using System.Collections;

namespace Lab_13
{
    [Serializable]
    public class CARTOONS : TV_program
    {
        public string StartTIME;
        public string _startTime
        {
            get { return StartTIME; }
            set => StartTIME = value;
        }
        public override void start_time(string time)
        {
            Console.WriteLine("Время начала: {0}", time);
            this.StartTIME = time;
        }
        public string _name;
        public string name_
        {
            get { return _name; }
            set { _name = value; }
        }
        public override void name(string n)
        {
            Console.WriteLine("Название: {0}", n);
            this._name = n;
        }
        [NonSerialized]
        public string _ageRestrictions;
        public string AgeRegistr
            { get { return _ageRestrictions; } set { _ageRestrictions = value; } }
        public override void age_restrictions(string age)
        {
            Console.WriteLine("Возрастное ограничение: {0}", age);
            this._ageRestrictions = age;
        }
       
        public string _country;
        public string Country_
            { get { return _country; } set { _country = value; } }
        public override void country(string country)
        {
            Console.WriteLine("Страна: {0}", country);
            this._country = country;
        }

        public CARTOONS(string startTIME, string _NAME, string ageRestrictions, string country)
        {
            _startTime = startTIME;
            name_ = _NAME;
            AgeRegistr = ageRestrictions;
            Country_ = country;
        }

        public CARTOONS()
        { }

        //ПЕРЕОПРЕДЕЛНИЕ БАЗОВОГО КЛАССА
        public override string ToString()
        {
            Console.WriteLine("Информация про мультики: ");
            Console.WriteLine("Время начала: {0}", StartTIME);
            Console.WriteLine("Название: {0}", _name);
            Console.WriteLine("Возрастные ограничения: {0}", _ageRestrictions);
            Console.WriteLine("Страна: {0}", _country);
            return "";
        }
    }
}
