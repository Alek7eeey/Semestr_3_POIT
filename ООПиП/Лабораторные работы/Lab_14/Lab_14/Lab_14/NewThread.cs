using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_14
{
    public class NewThread
    {
        public static void OutputNumber(object? n)
        {
            TwoThread.mutexObj.WaitOne();
            using (StreamWriter sr = new("Ex2.txt", false));
            Thread.Sleep(0);

            for (int i = 1; i <= Convert.ToInt32(n); i++)
            {
                Console.Write(i + " ");

                using(StreamWriter sr = new("Ex2.txt", true))
                {
                    sr.Write(i + " ");
                }
            }
            TwoThread.mutexObj.ReleaseMutex();
        }

        public static void CreateThread(int n)
        {
            Thread myThread = new (new ParameterizedThreadStart(OutputNumber));
            myThread.Start(n);          
            myThread.Name = ("CreateThread");
            Console.WriteLine("Имя потока: " + myThread.Name + "\t Приоритет: " + myThread.Priority + "\t Числовой идентификатор: " + myThread.ManagedThreadId
                + "\t Состояние потока: " + myThread.ThreadState);
        }
    }
}
