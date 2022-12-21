using SET;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SET
{
    static class Program_3
    {
        public static int Print_num1(this Program El, string title, Set<int> set)
        {
            var time_val = 0;
            foreach (var item in set)
            {
                Console.Write(title);
                Console.WriteLine($"{title}{item} ");
                time_val = item;
                break;
            }
            return time_val;
        }

        public static void Delete_positive_elements(this Program El, Set<int> set, string title)
        {
            Console.Write(title);
            foreach (var item in set)
            {
                if (item > 0)
                {
                    Console.Write($"{item} ");
                }
            }
            Console.WriteLine();
        }
    }
}
