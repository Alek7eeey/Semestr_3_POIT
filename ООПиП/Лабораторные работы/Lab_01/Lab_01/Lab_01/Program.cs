﻿using System;
using System.Text;

namespace LAB1
{
    class CL1
    {
        static void Main(string[] args)
        {
            //типы данных
            bool check = true;
            byte bMin = byte.MinValue; //1 byte
            byte bMax = byte.MaxValue;
            int iMax = int.MaxValue; //4 byte
            int iMin = int.MinValue;
            double dMin = double.MinValue; //8byte
            double dMax = double.MaxValue;
            float fMin = float.MinValue; //4 byte
            float fMax = float.MaxValue;
            long lMin = long.MinValue; //8 byte
            long lMax = long.MaxValue;
            decimal deMin = decimal.MinValue; //5...17byte
            decimal deMax = decimal.MaxValue;
            short shMin = short.MinValue; //2 byte
            short shMax = short.MaxValue;
            uint uiMin = uint.MinValue; //4 byte
            uint uiMax = uint.MaxValue;
            object b = 184; //4 - 32, 8 - 64
            object c = "How are you?";
            string str = "Abbbb";
            char strCh = 'A'; //2 byte

            //ввод - вывод
            Console.WriteLine("Строка: {0}", str);
            Console.WriteLine("Введите строку: ");
            str = Console.ReadLine();
            Console.WriteLine("Новая строка: {0}", str);

            Console.WriteLine("\nМаксимальное значение типа int - {0}", iMax);
            Console.WriteLine("Введите целочисленное значение: ");
            iMax = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Новое значение: {0}", iMax);

            Console.WriteLine("\nМинимальное значение типа double - {0}", dMin);
            Console.WriteLine("Введите значение с плавающей точкой: ");
            dMin = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Новое значение: {0}\n", dMin);

            //приведение
            byte a = 4;             // 0000100
            double doub_var = 14.14;
            int s = 5;
            double m = s + doub_var;
            doub_var = s;
            long Lon_var = 85566;
            m = Lon_var;
            long Ln_var = s;
            int k = -5;
            byte bt_var = 156;
            k = bt_var;
            double df = 15.777;

            double dbl = (double)df;
            int max = 9648;
            double dbl_v = (double)max;
            dbl_v = 14.33;
            max = (int)dbl_v;
            short ml = 98;
            int x = (int)ml;
            x = 1777;
            ml = (short)x;

            //*Convert - преобразует значение одного базового типа данных к другому базовому типу данных

            //упаковка ---------- сохраняет его в управляемой куче (хипе)
            int i = 123;
            object o = i;

            //распаковка
            o = 123;
            i = (int)o;

            //неявно типизированная переменная
            var n1 = 66;
            var n2 = 12.5;
            var sum = n1 + n2;
            var str_v = "Hello!";

            //Nullable
            int? numin1 = null; //упрощённая форма
            int? numin2 = null;
            Nullable<int> numin3 = 15; //полная форма

            bool mt = numin1.HasValue; //возвращает true, если объект хранит некоторое значение, и false, если объект равен null.

            Console.WriteLine(numin1.GetValueOrDefault()); //возвращает значение переменной/параметра, если они не равны null. Если они равны null, то возвращается значение по умолчанию    
            Console.WriteLine(numin1.GetValueOrDefault(10));

            //var 
            var sm = 15;
            sm = 'a';

            //Строки
            string str_1 = "Hello";
            string str_2 = "friends";

            int result = string.Compare(str_1, str_2); //сравнение по алфавиту
            if (result < 0)
            {
                Console.WriteLine("\nСтрока s1 первая по алфавиту ");
            }
            else if (result > 0)
            {
                Console.WriteLine("\nСтрока s2 первая по алфавиту");
            }
            else
            {
                Console.WriteLine("\nСтроки s1 и s2 идентичны");
            }

            string str_3 = str_1 + " " + str_2; //+ join + Concat

            //Сцепление (конкатенация строк)
            Console.WriteLine("Cцепление: {0}", str_3);

            //Копирование
            string s4 = string.Copy(str_3);
            Console.WriteLine("Копирование: {0}", s4);

            //вставка подстроки
            string str_5 = str_1.Insert(5, ", world");
            Console.WriteLine("Вставка подстроки в заданную позицию: {0}", str_5);

            //разбиение строки по грамницам слов
            string phrase = "How are you";
            string[] words = phrase.Split(' ');

            System.Console.WriteLine("\nРазделение на слова:");
            foreach (string word in words) //цикл
            {
                System.Console.WriteLine(word);
            }

            //удаление заданной подстроки + выделение строки
            string str_6 = str_3.Substring(6);
            Console.WriteLine("Выделение подстроки: {0}", str_6);

            Console.WriteLine($"Удаление заданной подстроки: {phrase.Remove(4)}");

            //пустая строка или нет?
            string s1 = "abcd";
            string s2 = "";
            string s3 = null;
            Console.WriteLine("\nПустая ли строка a1: {0}", String.IsNullOrEmpty(s1));
            Console.WriteLine("Пустая ли строка a2: {0}", String.IsNullOrEmpty(s2));
            Console.WriteLine("Пустая ли строка a3: {0}", String.IsNullOrEmpty(s3));
            Console.WriteLine($"2 строка = 3 строка: {s2 == s3}");
            Console.WriteLine($"Сцепление: {String.Concat(s3, s2)}");

            Console.WriteLine($"\nДинамическая строка:");
            var sb = new StringBuilder("Hello World"); //динамическая строка
            Console.WriteLine(sb.ToString());
            Console.WriteLine($"Длина: {sb.Length}");       // Длина: 10
            Console.WriteLine($"Емкость: {sb.Capacity}");   // Емкость: 16
            sb.Append(", end!");
            sb.Insert(0, "___");
            Console.WriteLine(sb.ToString());
            sb.Remove(5, 3); //(позиция, количество)
            Console.WriteLine(sb.ToString()); //вывод

            //Массивы

            //Двумерный массив (матрица)

            int[,] numbers = { { 1, 2, 3 }, { 4, 5, 6 } };

            /*ТАК ЖЕ МОЖНО:
            int[,] nums1;
            int[,] nums2 = new int[2, 3];
            int[,] nums3 = new int[2, 3] { { 0, 1, 2 }, { 3, 4, 5 } };
            int[,] nums4 = new int[,] { { 0, 1, 2 }, { 3, 4, 5 } };
            int[,] nums5 = new [,]{ { 0, 1, 2 }, { 3, 4, 5 } };
            int[,] nums6 = { { 0, 1, 2 }, { 3, 4, 5 } };
             */

            Console.WriteLine($"\nДвумерный массив (матрица):");
            int rows = numbers.GetUpperBound(0) + 1;
            int columns = numbers.Length / rows;

            for (int iv = 0; iv < rows; iv++)
            {
                for (int j = 0; j < columns; j++)
                {
                    Console.Write($"{numbers[iv, j]} \t");
                }
                Console.WriteLine();
            }

            /*ОДНОМЕРНЫЙ МАССИВ. Выведите на консоль его
            содержимое, длину массива. Поменяйте произвольный элемент
            (пользователь определяет позицию и значение)*/

            string[] people = { "Tom", "Sam", "Bob" };
            Console.WriteLine("\nДлина массива: {0}", people.Length);
            for (int iv = 0; iv < people.Length; iv++)
            {
                Console.WriteLine(people[iv]);
            }

            Console.WriteLine("Введите строку,на которую хотите заменить:");
            string str1 = Console.ReadLine();

            Console.WriteLine("Введите позицию(от 0 до 3):");
            int plase = Convert.ToInt32(Console.ReadLine());
            people[plase - 1] = str1;

            Console.WriteLine("\nНовый массив: ");
            for (int iv = 0; iv < people.Length; iv++)
            {
                Console.WriteLine(people[iv]);
            }


            /*Создайте ступечатый(не выровненный) массив вещественных
            чисел с 3 - мя строками, в каждой из которых 2, 3 и 4 столбцов
            соответственно.Значения массива введите с консоли. */

            double[][] myArr = new double[3][];
            myArr[0] = new double[2];
            myArr[1] = new double[3];
            myArr[2] = new double[4];
            Console.WriteLine();
            Console.WriteLine("\n*Введите элементы в ступенчатый массив ");
            int cif;

            Console.WriteLine("Введите элементы первой строки:");
            for (int iv = 0; iv < 2; iv++)
            {
                cif = Convert.ToInt32(Console.ReadLine());
                myArr[0][iv] = cif;
            }

            Console.WriteLine("\nВведите элементы второй строки:");
            Console.WriteLine();
            for (int iv = 0; iv < 3; iv++)
            {
                cif = Convert.ToInt32(Console.ReadLine());
                myArr[1][iv] = cif;
            }

            Console.WriteLine("\nВведите элементы третьей строки:");
            Console.WriteLine();
            for (int iv = 0; iv < 4; iv++)
            {
                cif = Convert.ToInt32(Console.ReadLine());
                myArr[2][iv] = cif;
            }

            Console.WriteLine();
            Console.WriteLine($"\nСтупенчатый массив: ");
            for (int iv = 0; iv < myArr.Length; iv++)
            {
                for (int j = 0; j < myArr[iv].Length; j++)
                {
                    Console.Write($"{myArr[iv][j]} \t");
                }
                Console.WriteLine();
            }

            //неявно типизированные переменные
            var A = new[] { 6, 2 };
            var X = new[] { "Andrey", "Artem", "Alex" };
            var B = "This is lab 1";

            //КОРТЕЖИ

            //Кортеж из 5 элементов с типами int, string, char, string, ulong
            (int, string, char, string, ulong) kortezh = (19, "Hi", 'F', "world", 9999999);

            //Вывод кортежа на консоль целиком и выборочно(например 1,3, 4 элементы)
            Console.WriteLine("\nКортеж целиком: {0}", kortezh);
            Console.WriteLine("Элементы кортежа 1, 3, 4: {0} {1} {2}", kortezh.Item1, kortezh.Item3, kortezh.Item4);

            var (first, second, third, four, five) = kortezh; //можно вынести var за скобки
            (var fr, _, _, _, _) = kortezh;
            int fir;
            (fir, _, _, _, _) = kortezh;

            //сравнение кортежей
            var tuple1 = (23, 36);
            var tuple2 = (17, 31);
            Console.WriteLine("Кортежи равны:{0} ", tuple1 == tuple2);
            Console.WriteLine("Кортежи не равны:{0} ", tuple1 != tuple2);

            //ФУНКЦИИ

            //Формальные параметры функции – массив
            //целых и строка. Функция должна вернуть кортеж, содержащий: 
            //максимальный и минимальный элементы массива, сумму элементов
            //массива и первую букву строки

            (int, int, int, char) Localfunction(int[] numbers, string str1)
            {
                int max = 0;
                int min = Int32.MaxValue;
                int sum = 0;

                for (int i = 0; i < numbers.Length; i++)
                {
                    if (numbers[i] > max)
                    {
                        max = numbers[i];
                    }
                    if (numbers[i] < min)
                    {
                        min = numbers[i];
                    }
                    sum += numbers[i];
                }
                char smb = str1[0];
                var tuple1 = (max, min, sum, smb);
                return tuple1;
            }
            //Вызов
            int[] ARR1 = { 10, 2000, 30, 11 };
            string STR1 = "abc";
            Console.WriteLine($"\nРезультат вызова функции: ");
            Console.WriteLine(Localfunction(ARR1, STR1));

            //Разместите в одной из них блок checked, в котором определите
            //переменную типа int с максимальным возможным значением
            //этого типа. Во второй функции определите блок unchecked с
            //таким же содержимым

            int z2 = 1;
            int localfunction2()
            {
                int z1 = Int32.MaxValue;

                unchecked //результат усекается, чтобы не выйти за пределы диапазона представления чисел для целевого типа выражения
                {
                    z1 += z2;
                    Console.WriteLine(z1);
                }
                return z1;
            }

            int localfunction1()
            {
                int z1 = Int32.MaxValue;
                checked
                {
                    z1 += z2;
                    Console.WriteLine(z1);
                }
                return z1;
            }

            Console.WriteLine(localfunction2()); //мусор выведится

            try
            {
                Console.WriteLine(localfunction1());
            }

            catch {
                Console.WriteLine("Ошибка!");
            }
        }
    }
}
