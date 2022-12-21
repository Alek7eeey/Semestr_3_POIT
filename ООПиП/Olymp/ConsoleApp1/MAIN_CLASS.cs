using System;
using System.Drawing;
using System.Xml;

class Olymp
{
    public static void Main(string[] args)
    {

        string[] cost;
        cost = Console.ReadLine().Split(' ');
        int A = Convert.ToInt32(cost[0]);
        int B = Convert.ToInt32(cost[1]);
        int C = Convert.ToInt32(cost[2]);

        int[] arr = new int[6];

        cost = Console.ReadLine().Split(' ');
        int x1 = Convert.ToInt32(cost[0]);
        int x2 = Convert.ToInt32(cost[1]);
        arr[0] = x1;
        arr[1] = x2;

        cost = Console.ReadLine().Split(' ');
        int y1 = Convert.ToInt32(cost[0]);
        int y2 = Convert.ToInt32(cost[1]);
        arr[2] = y1;
        arr[3] = y2;

        cost = Console.ReadLine().Split(' ');
        int z1 = Convert.ToInt32(cost[0]);
        int z2 = Convert.ToInt32(cost[1]);
        arr[4] = z1;
        arr[5] = z2;

        for (int i = 0; i < 6 - 1; i++)
        {
            for (int j = 0; j < 6 - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        int result = ((arr[5] - arr[4]) * A) + (2 * ((arr[4] - arr[3]) * B)) + (3 * ((arr[3] - arr[2]) * C)) + (2 * ((arr[2] - arr[1]) * B)) + ((arr[1] - arr[0]) * A);
        Console.WriteLine(result);
    }
}