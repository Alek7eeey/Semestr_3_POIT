using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_15
{
    public static class SortedArray
    {
        static Random random = new();
        static int[] arr2 = new int[10];

        public static int BubbleSort(int n)
        {
            int[] arr = new int[n];
            Console.Write("\nМассив: ");
            for(int i = 0; i<n;i++)
            {
                Thread.Sleep(200);
                arr[i] = random.Next(0,10);
                Console.Write(arr[i] + " ");
            }
            Console.WriteLine();
            int temp;
            for (int i = 0; i < arr.Length; i++)
            {
                for (int j = i + 1; j < arr.Length; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            Console.Write("Отсортированный массив: ");
            for(int i = 0; i<arr.Length; i++)
            {
                Thread.Sleep(200);
                Console.Write(arr[i] + " ");
            }
            return 0;
        }
    }
}
