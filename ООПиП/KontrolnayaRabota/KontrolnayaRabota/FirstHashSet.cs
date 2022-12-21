using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KontrolnayaRabota
{
    public class FirstHashSet <T> where T: class
    {
        public HashSet<T> set = new();

        public void Add(T num)
        {
            set.Add(num);
        }

        public void print()
        {
            foreach (T num in set)
            {
                num.ToString();
                Console.WriteLine();
            }
        }

        public void deleteEl(T el)
        {
            set.Remove(el);
        }

        public void clear() { set.Clear(); }
    }
}
