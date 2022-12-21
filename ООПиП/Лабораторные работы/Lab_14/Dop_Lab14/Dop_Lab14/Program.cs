using System;
using System.Threading;
using System.Diagnostics;

namespace Dop_Lab_14
{
    class Program
    {
        static void Main(string[] argv)
        {
            
            for (int i = 1; i < 4; i++)
            {
                Driver driver = new Driver(i);
            }
        }
        class Driver
        {
            static Semaphore sem = new Semaphore(1, 1);
            Thread myThread;
            static int countProduct = 150;
            static int Count2 = 0;

            public static void Cars(object? _countProduct)
            {
                int n = Convert.ToInt32(_countProduct);                

                while (countProduct > 0)
                {
                    sem.WaitOne();  // ожидаем, когда освободиться место

                    countProduct -= n;

                    if(countProduct<=0)
                    {
                        if (countProduct <= 0 && Count2 != 0)
                        {
                            sem.Release();
                        }

                        else
                        {
                            Count2++;
                            Console.WriteLine($"{Thread.CurrentThread.Name} водитель загрузил груза - {_countProduct}, осталось - 0");
                        }
                    }

                    else
                    {
                        Console.WriteLine($"{Thread.CurrentThread.Name} водитель загрузил груза - {_countProduct}, осталось - {countProduct}");
                        sem.Release();  // освобождаем место
                    }
                }
            }

            public Driver(int i)
            {
                myThread = new (new ParameterizedThreadStart(Cars));
                myThread.Name = $"Водитель {i}";
                myThread.Start(i+10);
            }

        }
    }
}
