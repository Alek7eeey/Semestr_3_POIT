using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_14
{
     public static class OutputSequence
    {
        static public AutoResetEvent waitHandler = new (true);  // объект-событие
        public static void EvenNum(object n)
        {
            
            for (int i = 1; i <= Convert.ToInt32(n); i++)
            {
                if (i % 2 == 0)
                {
                    //Thread.Sleep(500);
                    waitHandler.WaitOne();
                    Console.Write(i + " ");
                    using (StreamWriter sr = new("Ex3-2.txt", true))
                    {
                        sr.Write(i + " ");
                    }
                    waitHandler.Set();
                }
            }
        }

        public static void OddNum(object n)
        {
            for (int i = 1; i <= Convert.ToInt32(n); i++)
            {
                if (i % 2 != 0)
                {
                    //Thread.Sleep(510);
                    //Console.Write(i + " ");
                    waitHandler.WaitOne();
                    Console.Write(i + " ");
                    using (StreamWriter sr = new("Ex3-2.txt", true))
                    {
                        sr.Write(i + " ");
                    }
                    waitHandler.Set();
                }
            }
        }

        public static void _OutputSequence(int n)
        {
            Thread.Sleep(1500);
            using (StreamWriter sr = new("Ex3-2.txt", false)) ;
            Console.WriteLine();
            Thread myThread = new(new ParameterizedThreadStart(EvenNum));
            Thread myThread2 = new(new ParameterizedThreadStart(OddNum));
            myThread.Start(n);
            myThread2.Start(n);

        }
    }
}
