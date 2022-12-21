using SET;
using System;

namespace SET
{
    class Program
    {
        static void Main(string[] args)
        {
            var set1 = new Set<int>()
            {
                -1, 2, 3, 4, 5, -6
            };


            var set2 = new Set<int>()
            {
                4, 5, 6, 7, 8, 9
            };

            var set3 = new Set<int>()
            {
                2, 3, 4
            };

            var res1 = set1 < set2;
            if(res1==true)
            {
                Console.WriteLine("Все элементы первого множества присутствуют во втором => это подмножество");
            }
            else
            {
                Console.WriteLine("элементы первого множества не присутствуют во втором => это не подмножество!");
            }
            Console.WriteLine();

            var intersection = set1*set2;
            var subset1 = Set<int>.Subset(set3, set1);
            var subset2 = Set<int>.Subset(set3, set2);

            PrintSet(set1, "Первое множество: ");
            PrintSet(set2, "Второе множество: ");
            PrintSet(set3, "Третье множество: ");
            Console.WriteLine();

            Program El = new();
            El.Print_num1("Первый элемент первого множества: ", set1);
            El.Print_num1 ("Первый элемент второго множества: ", set2);
            El.Print_num1("Первый элемент третьего множества: ", set3);
            Console.WriteLine();

            El.Delete_positive_elements(set1,"Положительные элементы первого множества: ");
            El.Delete_positive_elements(set2, "Положительные элементы второго множества: ");
            El.Delete_positive_elements(set3, "Положительные элементы третьего множества: ");
            Console.WriteLine();

            PrintSet(intersection, "Пересечение первого и второго множества: ");
            Console.WriteLine();

            // Выводим результаты проверки на подмножества.
            if (subset1)
            {
                Console.WriteLine("Третье множество является подмножеством первого.");
            }
            else
            {
                Console.WriteLine("Третье множество не является подмножеством первого.");
            }

            if (subset2)
            {
                Console.WriteLine("Третье множество является подмножеством второго.");
            }
            else
            {
                Console.WriteLine("Третье множество не является подмножеством второго.");
            }

            Console.WriteLine();
            
            var res2 = set1 > set2;
            if (res2 == true)
            {
                Console.WriteLine("Число 0 принадлежит!");
            }

            if (res2 == false)
            {
                Console.WriteLine("Число 0 не принадлежит!");
            }


            Console.WriteLine("\n------------------------------------");

            INFORMATION.Production.Name = "Laba_3";
            INFORMATION.Production.ID = 1;

            Console.WriteLine("Информация про лабораторную: ");
            Console.WriteLine("Название лабораторной: {0}", INFORMATION.Production.Name);
            
            INFORMATION.Developer devop = new INFORMATION.Developer();

            Console.WriteLine("Автор: {0}", devop.name_developer);
            Console.WriteLine("Группа: {0}", devop.department);

            //приведение типов (Date() == employee)
            INFORMATION.emlpoyee empl = new("aleksey", "5 poit");
            INFORMATION.Person per = empl;

            Console.ReadLine();
        }


        /// Вывод множества на консоль.
        private static void PrintSet(Set<int> set, string title)
        {
            Console.Write(title);
            foreach (var item in set)
            {
                Console.Write($"{item} ");
            }
            Console.WriteLine();
        }
    }
}