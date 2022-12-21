using KontrolnayaRabota;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Runtime.Intrinsics.X86;
using System.Text;
using System.Threading.Tasks;

namespace Lab_10
{
    partial class Program
    {
        public delegate void deleg1();
        public delegate void deleg2(string text);

        public static event deleg1 Click;
        public static event deleg2 OutPut;
        public static void Main(string[] argv)
        {
            #region ex1
            FirstHashSet<Person> set = new FirstHashSet<Person>();
            Person p1 = new Person(1999,"Aleksey");
            Person p2 = new Person(2003, "Andrey");
            Person p3 = new Person(1998, "Filipp");
            Person p4 = new Person(1978, "Polina");
            set.Add(p1);
            set.Add(p2);
            set.Add(p3);
            set.Add(p4);
            set.deleteEl(p3);
            set.print();
            #endregion

            #region ex2
            var count = (from c in set.set select c).Count();
            Console.WriteLine("Количество элементов в коллекции: " + count);
            #endregion

            #region ex3
            PC pc = new PC(1);
            Button bt = new Button();
            
            Click += bt.click;
            OutPut+= bt.outPut;

            if(pc.count== 1) 
            {
                Click();
            }
            else
            {
                OutPut("\nКомпьютеров: " + pc.count);
            }
            #endregion
        }
    }

}