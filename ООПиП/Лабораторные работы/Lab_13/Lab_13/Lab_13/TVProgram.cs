using System;
using System.Collections;

namespace Lab_13
{
    [Serializable]
    public abstract class TV_program
    {
        public abstract void start_time(string time);
        public abstract void name(string name);
        public abstract void age_restrictions(string age);
        public abstract void country(string country);

    }
}
