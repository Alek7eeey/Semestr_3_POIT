using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_14
{
    public static class TwoThread
    {
        public static Mutex mutexObj = new();
        public static void EvenNum(object n)
        {
            mutexObj.WaitOne();

            Console.WriteLine();

            for (int i = 1; i <= Convert.ToInt32(n); i++)
            {
                if (i % 2 == 0)
                {
                    Console.Write(i + " ");

                    using (StreamWriter sr = new("Ex3.txt", true))
                    {
                        sr.Write(i + " ");
                    }
                }
            }
            mutexObj.ReleaseMutex();    // освобождаем мьютекс
        }

        public static void OddNum(object n)
        {
            mutexObj.WaitOne();
            Thread.Sleep(500);
            //using (StreamWriter sr = new("Ex3.txt", false)) ;
            Console.WriteLine();

            for (int i = 1; i <= Convert.ToInt32(n); i++)
            {
                if (i % 2 != 0)
                {
                    Console.Write(i + " ");

                    using (StreamWriter sr = new("Ex3.txt", true))
                    {
                        sr.Write(i + " ");
                    }
                }
            }
            mutexObj.ReleaseMutex();    // освобождаем мьютекс
        }

        public static void CreateThread(int n)
        {
            using (StreamWriter sr = new("Ex3.txt", false));

            Thread myThread = new(new ParameterizedThreadStart(EvenNum));
            myThread.Priority = ThreadPriority.Highest;
            Thread myThread2 = new(new ParameterizedThreadStart(OddNum));
            myThread2.Priority = ThreadPriority.Lowest;

            myThread.Start(n);
            Thread.Sleep(500);
            myThread2.Start(n);

            myThread.Name = ("CreateThread_1");
            myThread2.Name = ("CreateThread_2");

        }
    }
}
