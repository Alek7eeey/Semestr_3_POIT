using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_15
{
    public static class FilingArray
    {
        static Random random = new();
        static int[] arr = new int[1000000];
        static Stopwatch stopWatch = new ();
        public static void aaa()
        {
            stopWatch.Start();
            Parallel.For(0, 1000000, CreateArr);
            stopWatch.Stop();
            TimeSpan ts = stopWatch.Elapsed;
            Console.WriteLine("\nВремя выполнения Parallel.For: " + ts);
            stopWatch.Reset();

            stopWatch.Start();
            for (int i = 0; i < arr.Length; i++)
            {
                CreateArr(i);
            }
            stopWatch.Stop();
            TimeSpan ts2 = stopWatch.Elapsed;
            Console.WriteLine("Время выполнения For: " + ts2);
            stopWatch.Reset();
        }

        public static void bbb()
        {
            stopWatch.Start();

            Parallel.ForEach<int>(
            arr,
            CreateArr
            );

            stopWatch.Stop();
            TimeSpan ts4 = stopWatch.Elapsed;
            Console.WriteLine("\nВремя выполнения Parallel.ForEach: " + ts4);
            stopWatch.Reset();

            stopWatch.Start();
            foreach (var item in arr)
            {
                CreateArr(item);
            }
            stopWatch.Stop();
            TimeSpan ts3 = stopWatch.Elapsed;
            Console.WriteLine("Время выполнения foreach: " + ts3);
            stopWatch.Reset();

        }
        public static void CreateArr(int i)
        {
            arr[i] = random.Next(0,15);
        }

    }
}
