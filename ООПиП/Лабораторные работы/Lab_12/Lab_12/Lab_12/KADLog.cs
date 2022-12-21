using Lab_12;
using System;
using System.Linq;
using System.Text;
using System.IO;
using System.Data;

namespace Lab_12
{
    /*1. Создать класс XXXLog. Он должен отвечать за работу с текстовым файлом xxxlogfile.txt.
      в который записываются все действия пользователя и соответственно методами записи в текстовый файл,
      чтения, поиска нужной информации. Используя данный класс выполните запись всех последующих действиях пользователя с указанием действия,
      детальной информации (имя файла, путь) и времени (дата/время) */
    class KADLog
    {
        static public string path = "kadlogfile.txt";
        static public void Write(string? name, string? action)
        {
            if (name is null)
            {
                throw new ArgumentNullException(nameof(name));
            }
            if (action is null)
            {
                throw new ArgumentNullException(nameof(action));
            }

            Information inf = new (name,action, DateTime.Now);


                using (StreamWriter writer = new(path, true))
                {
                    writer.WriteLine(inf);
                }
        }

        static public void ReadAndFind(string date, string TimeStart, string EndTime)
        {
            int countOfEntry = 0;
            string info = File.ReadAllText(path);

            if (info is null)
            {
                throw new ArgumentNullException(nameof(info));
            }

            foreach(var item in info)
            {
                Console.Write(item);
            }

            string[] arr = info.Split('\n');
            string[] arr2 = info.Split(' ', '\n');
            foreach (string item in arr2)
            {
                if (item == "end")
                    countOfEntry++;
            }

            int countDate = 0;
            Console.WriteLine("\nИНФОРМАЦИЯ ЗА УКАЗАННОЕ ЧИСЛО:");
            for (int i = 0; i < arr2.Length; i++)
            {   
                if(arr2[i] == date)
                {
                    Console.WriteLine(arr2[i]+ ' ' + arr2[i+1] + ' ' + arr2[i+2] + ' ' + arr2[i+3]);
                    i += 3;
                    countDate++;
                }
                if(arr2[i] == "Main")
                    Console.WriteLine('\n');
            }

            if(countDate == 0)
                Console.WriteLine("Информации за указанное число не найдено!");

            int CountTime = 0;
            Console.WriteLine("\nИНФОРМАЦИЯ ЗА УКАЗАННОЕ ВРЕМЯ:");
            for (int i = 0; i < arr2.Length; i++)
            {
                if (arr2[i].Contains(':'))
                {
                    if (TimeOnly.Parse(arr2[i]) > TimeOnly.Parse(TimeStart) && TimeOnly.Parse(arr2[i]) < TimeOnly.Parse(EndTime))
                    {
                        Console.WriteLine(' ' + arr2[i-1]+ ' ' + arr2[i] + ' ' + arr2[i + 1] + ' ' + arr2[i + 2] + ' ' + arr2[i + 3]);
                        i += 2;
                        CountTime++;
                    }
                    if (arr2[i] == "Main")
                        Console.WriteLine('\n');
                }
            }

            if(CountTime == 0)
            {
                Console.WriteLine("Ничего не найдено!");
            }

            Console.WriteLine("\n---------------------------------");
            Console.WriteLine("\nКоличество записей: " + countOfEntry);
            Console.WriteLine("Количество строк: " + (arr.Length-1));

        }

        static public void DeleteInfPerHour()
        {
            int newCount = 0;
            string info = File.ReadAllText(path);
            string[] arr2 = info.Split(' ', '\n');
            
            for (int i = 0; i < arr2.Length; i++)
            {
                if (arr2[i].Contains(':'))
                {
                    if (TimeOnly.Parse(arr2[i]) > TimeOnly.Parse(DateTime.Now.ToString("t")).AddHours(-1) && TimeOnly.Parse(arr2[i]) < TimeOnly.Parse(DateTime.Now.ToString("t")))
                    {
                        i += 2;
                        newCount++;
                        if(newCount == 1)
                        {
                            using (StreamWriter writer = new(path, false))
                            {
                                writer.WriteLine(' ' + arr2[i - 1] + ' ' + arr2[i] + ' ' + arr2[i + 1] + ' ' + arr2[i + 2] );
                            }
                        }

                        else
                        {
                            using (StreamWriter writer = new(path, true))
                            {
                                writer.WriteLine(' ' + arr2[i - 1] + ' ' + arr2[i] + ' ' + arr2[i + 1] + ' ' + arr2[i + 2] );
                            }
                        }
                        
                    }

                    if (arr2[i] == "Main")
                        using (StreamWriter writer = new(path, true))
                        {
                            writer.WriteLine('\n');
                        }
                }
            }
        }

        public class Information
        {
            public string Name { get; set; }
            public string Action { get; set; }
            public DateTime DateTime { get; set; }

            public Information(string _name, string _action, DateTime _dateTime)
            {
                Name = _name;
                this.Action = _action;
                DateTime = _dateTime;
            }

            public override string ToString() => $"{DateTime} {Action} {Name}";
        }
    }
}