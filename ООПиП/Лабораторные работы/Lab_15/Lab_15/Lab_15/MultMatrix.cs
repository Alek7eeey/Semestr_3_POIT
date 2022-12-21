using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_15
{
    public static class MultMatrix
    {
        static Random random = new();
        public static void MultiplicationMatrix(int str, int col)
        {
            int[,] matrixA = new int[str, col];
            int[,] matrixB = new int[str, col];
            int[,] resultMatrix = new int[str, col];

            for (int i = 0; i < str; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    matrixA[i, j] = random.Next(0,10);
                    matrixB[i, j] = random.Next(0,10);
                }
            }

            Console.WriteLine("\nМатрица А:");
            //A
           for (int i = 0; i < str; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    Console.Write(matrixA[i,j] + "\t");
                }
                Console.WriteLine();
            }
            Console.WriteLine("\nМатрица В:");
            //B
            for (int i = 0; i < str; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    Console.Write(matrixB[i, j] + "\t");
                }
                Console.WriteLine();
            }

            for(int i = 0; i < str; i++)
            {
                for(int j = 0; j < col; j++)
                {
                    for(int k = 0; k < col; k++)
                    {
                        resultMatrix[i, j] += matrixA[i, k] * matrixB[k, j];
                    }
                }
            }
            Console.WriteLine("\nМатрица A*B:");
            //A*B
            for (int i = 0; i < str; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    Console.Write(resultMatrix[i, j] + "\t");
                }
                Console.WriteLine();
            }

        }
    }
}
