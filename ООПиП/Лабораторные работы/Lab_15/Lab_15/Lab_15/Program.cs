
using System.Collections.Concurrent;
using System.Diagnostics;
using System.Threading.Tasks;

namespace Lab_15
{
    class Program
    {
       static void Main(string[] argv)
        {
            int n = 20;
            #region Zadanie1
            //Задание_1
            Stopwatch stopWatch = new Stopwatch();
            Task Task1 = new(() => SearchSimpleNum.ReshetoEratosfena(n)); //все простые числа из 20
            stopWatch.Start();
            Task1.Start();
            Task1.Wait();
            stopWatch.Stop();
            Thread.Sleep(1000);
            TimeSpan ts = stopWatch.Elapsed;
            Console.WriteLine("Время выполнения задачи " + Task1.Id + ": " + ts);
            Console.WriteLine("Идентификатор текущей задачи:" + Task1.Id + "\tСтатус задачи:" + Task1.Status + "\tЗадача завершена:" + Task1.IsCompleted);
            stopWatch.Reset();
            Thread.Sleep(1000);
            Console.WriteLine();

            Task Task2 = new(() => MultMatrix.MultiplicationMatrix(5, 3)); //матрица вида 5х3
            stopWatch.Start();
            Task2.Start();
            Task1.Wait();
            stopWatch.Stop();
            TimeSpan ts2 = stopWatch.Elapsed;
            Console.WriteLine("Время выполнения задачи " + Task2.Id + ": " + ts2);
            Console.WriteLine("Идентификатор текущей задачи:" + Task2.Id + "\tСтатус задачи:" + Task2.Status + "\tЗадача завершена:" + Task1.IsCompleted);
            stopWatch.Reset();
            Task2.Wait();
            #endregion

            #region Zadanie2
            //Задание_2
            CancellationTokenSource cancelTokenSource = new();
            CancellationToken token = cancelTokenSource.Token;
            Console.WriteLine();
            Task task = new(() =>
            {
                for (int i = 1; i < 10; i++)
                {
                    if (token.IsCancellationRequested)  // проверяем наличие сигнала отмены задачи
                    {
                        Console.WriteLine("Операция прервана");
                        return;     //  выходим из метода и тем самым завершаем задачу
                    }
                    Console.WriteLine($"Квадрат числа {i} равен {i * i}");
                    Thread.Sleep(200);
                }

            }, token);

            task.Start();

            Thread.Sleep(1000);
            // после задержки по времени отменяем выполнение задачи
            cancelTokenSource.Cancel();
            Thread.Sleep(1000);
            cancelTokenSource.Dispose(); 
            #endregion

            #region Zadanie3
            Task<int> task1Ex3 = new(() => Formula._mul(5, 2, 3));
            Task<int> task2Ex3 = new(() => Formula._sum(2, 3, 5));
            Task<int> task3Ex3 = new(() => Formula._pow(2, 3));

            Task task4Ex3 = new(() =>
            {
                int result = 0;

                result = task1Ex3.Result + task2Ex3.Result + task3Ex3.Result;
                Console.WriteLine("\nРезультат вычислений: " + result);
            });

            task1Ex3.Start();
            task1Ex3.Wait();
            task2Ex3.Start();
            task2Ex3.Wait();
            task3Ex3.Start();
            task3Ex3.Wait();
            task4Ex3.Start();
            task4Ex3.Wait();
            //можно было сделать, как вложенные задачи


            #endregion

            #region Zadanie4
            //var_1
            Task<int> task1Ex4 = new(() => Formula._sum(2, 5, 6, 10));
            Task task2Ex4 = task1Ex4.ContinueWith(task =>
            {
                Console.WriteLine("\nСумма: " + task1Ex4.Result);
            });

            task1Ex4.Start();
            task2Ex4.Wait();

            //var_2
            Task task3Ex4 = new(() =>
            {
                string str1 = "\nHello";
                Console.WriteLine(str1);
            });
            task3Ex4.Start();
            task3Ex4.GetAwaiter().GetResult();

            #endregion

            #region Zadanie5

            SortedArray.BubbleSort(5);
            Console.WriteLine("\n-------------");
            FilingArray.aaa();
            FilingArray.bbb();

            #endregion

            #region Zadanie_6
            Console.WriteLine();

            Parallel.Invoke(
                () => Formula._sumOutput(10, 5, 6, 7),
                () => Formula._mulOutput(5, 2, 3),
                () => Formula._powOutput(3, 2)
                );

            #endregion

            #region Zadanie_7
            /*
             Есть 5 поставщиков бытовой техники, они завозят уникальные товары на склад (каждый по одному) и 10 покупателей – покупают все подряд,
             если товара нет - уходят. В вашей задаче: cпрос превышает предложение. Изначально склад пустой. У каждого поставщика своя
             скорость завоза товара. Каждый раз при изменении состоянии склада выводите наименования товаров на складе.
             */
            Console.WriteLine();
            Trade.TaskAsync();
            Console.ReadLine();

            #endregion
        }
    }
}
