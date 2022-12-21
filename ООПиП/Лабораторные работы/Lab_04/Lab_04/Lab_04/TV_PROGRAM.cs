using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


namespace LAB_4
{
    public abstract class TV_program
    {
        public abstract void start_time(string time);
        public abstract void duration(string dur);
        public abstract void age_restrictions(string age);
        public abstract void country(string country);

    }
}