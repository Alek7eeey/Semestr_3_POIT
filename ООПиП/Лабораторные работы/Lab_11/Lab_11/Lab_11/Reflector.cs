using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;
using Lab_11;
using System.Data;
using System.IO;
using System.Collections;

namespace Lab_11
{
    static class Reflector<T> where T : class, new()
    {
        private static Type type = typeof(T);
        private static string nameFile = "File.txt";

        #region methods
        public static string GetNameAssembly() 
        {
            Console.WriteLine($"Информация про сборку:   {type.Assembly.FullName}.");
            using (StreamWriter writer = new (nameFile, false))
            {
                writer.WriteLine("Сборка:" + type.Assembly.FullName);
            }

            return "";
        }

        public static void publicConstructor()
        {
            if(type.IsPublic)
            {
                Console.WriteLine("\nПубличный конструктор присутствует!\n");
                
                using (StreamWriter writer = new(nameFile, true))
                {
                    writer.WriteLine("\nПубличный конструктор присутствует!\n");
                }
            }
            else
            {
                Console.WriteLine("\nПубличный конструктор отсутсвует!\n");
                
                using (StreamWriter writer = new(nameFile, true))
                {
                    writer.WriteLine("\nПубличный конструктор отсутствует!\n");
                }
            }
        }

        public static void allPublicMethods()
        {
            Console.WriteLine("\nПубличные методы:");
            int count = 0;
            MethodInfo[] methods = type.GetMethods (BindingFlags.Public | BindingFlags.Instance | BindingFlags.DeclaredOnly);
            
            foreach (MethodInfo method in methods)
            {
                Console.WriteLine($"Название метода: {method.Name}");
                using (StreamWriter writer = new(nameFile, true))
                {
                    writer.WriteLine($"Название метода: {method.Name}");
                }

                count++;
            }
            if (count == 0)
            {
                Console.WriteLine("Public-методы отсутствуют");
                using (StreamWriter writer = new(nameFile, true))
                {
                    writer.WriteLine("\nPublic-методы отсутствуют");
                }
            }
        }

        public static void getInformationAboutFielgs()
        {
            Console.WriteLine("\nИнформация про поля и свойства:");
            using (StreamWriter writer = new(nameFile, true))
            {
                writer.WriteLine("\nИнформация про поля и свойства:");
            }
            int coubt = 0;

            FieldInfo[] fields = type.GetFields(BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Static);
            int i = 0;
            string nameType;

            foreach (var field in fields)
            {
                i++;
                nameType = field.FieldType.ToString(); // получить название типа поля field структуры Worker
                Console.Write($"\nПоле(свойство)[{i}] = {field.Name}, тип = {nameType}, модификатор доступа: ");
                using (StreamWriter writer = new(nameFile, true))
                {
                    writer.Write($"Поле(свойство)[{i}] = {field.Name}, тип = {nameType}, модификатор доступа: ");
                }

                if (field.IsStatic)
                {
                    Console.Write("static");
                    using (StreamWriter writer = new(nameFile, true))
                    {
                        writer.Write("static\n");
                    }
                }

                if (field.IsPublic)
                {
                    Console.Write("public");
                    using (StreamWriter writer = new(nameFile, true))
                    {
                        writer.Write("public\n");
                    }
                }

                if (field.IsPrivate)
                {
                    Console.Write("private");
                    using (StreamWriter writer = new(nameFile, true))
                    {
                        writer.Write("private\n");
                    }
                }
                Console.WriteLine();
                coubt++;
            }

            if (coubt == 0)
            {
                Console.WriteLine("Полей или свойств нету!");
                using (StreamWriter writer = new(nameFile, true))
                {
                    writer.WriteLine("\nПолей или свойств нету!");
                }
            }
        }

        public static void getInterface()
        {
            Type[] interfaces = type.GetInterfaces();
            int i = 0;
            foreach (Type t in interfaces)
            {
                i++;
                Console.WriteLine("\nИнтерфейс[{0}] = {1}", i, t.Name);
                using (StreamWriter writer = new(nameFile, true))
                {
                    writer.WriteLine("\nИнтерфейс[{0}] = {1}", i, t.Name);
                }

            }

            if(i == 0)
            {
                Console.WriteLine("\nКласс не наследуется от интерфейсов!");
                using (StreamWriter writer = new(nameFile, true))
                {
                    writer.WriteLine("\n\nКласс не наследуется от интерфейсов!");
                }
            }
        }

        public static void GetNameOfMethods(string TypeOfParams)
        {
            var param = Type.GetType(TypeOfParams);
            if (param != null)
            {
                var foo = type.GetMethods().Where(i => i.GetParameters().Any(item => item.ParameterType == param));

                if (foo.Count() > 0)
                {
                    Console.WriteLine($"\nМетоды:");
                    using (StreamWriter writer = new(nameFile, true))
                    {
                        writer.WriteLine("\nМетоды: ");
                    }
                    foreach (var item in foo) 
                    {
                        if (item.IsStatic)
                        {
                            Console.Write("static ");
                            using (StreamWriter writer = new(nameFile, true))
                            {
                                writer.Write("static ");
                            }
                        }
                        if (item.IsVirtual)
                        {
                            Console.Write("virtual ");
                            using (StreamWriter writer = new(nameFile, true))
                            {
                                writer.Write("virtual");
                            }
                        }
                        if (item.IsPublic)
                        {
                            Console.Write("public ");
                            using (StreamWriter writer = new(nameFile, true))
                            {
                                writer.Write("public ");
                            }
                        }
                        if (item.IsPrivate)
                        {
                            Console.Write("private ");
                            using (StreamWriter writer = new(nameFile, true))
                            {
                                writer.Write("private ");
                            }
                        }
                      Console.Write(item);
                        using (StreamWriter writer = new(nameFile, true))
                        {
                            writer.Write(item);
                        }
                    }
                }
                else
                {
                    Console.WriteLine("Методов с такими параметрами нету!");
                    using (StreamWriter writer = new(nameFile, true))
                    {
                        writer.WriteLine("\"Методов с такими параметрами нету!\" ");
                    }
                }
            }


        }

        public static void Invoke(string fileWithInformation)
        {
            //using StreamReader sr = new(fileWithInformation);
            //using (StreamReader reader = new (fileWithInformation))
            //{

            //    string allInf = reader.ReadLine();
            //    Console.WriteLine(allInf);
            //}
            string info = File.ReadAllText(fileWithInformation);
            //Console.WriteLine("\n" + info);
            Console.WriteLine('\n');

            info.Split(new char[] { ' ' });

            string name = String.Empty, 
                   par = String.Empty;

            int countOfPar = 0;

            for (int i = 0; i < info.Length; i++)
            {
                if (info[i] == '&')
                    countOfPar++;
            }

            countOfPar += 1;
            string[] allPar = new string[countOfPar];

            for (int i = 0; i < info.Length; i++)
            {

                if (info[i] == '(')
                {
                    for (int j = i + 1; j < info.Length - 1; j++)
                    {
                        par += info[j];
                    }
                    break;
                }
                else
                    name += info[i];
            }


            Console.WriteLine("-----------------");
            Console.WriteLine($"Будет вызвана функция {name}, и переданы параметры: {par}");

            string[] parametr = par.Split('&');
           
            int p1 = Convert.ToInt32(parametr[0]);
            double p2 = Convert.ToDouble(parametr[1]);

            MethodInfo methodInfo = type.GetMethod(name);

            if(methodInfo != null)
            {
                object result = null;
                ParameterInfo[] parameters = methodInfo.GetParameters();
                object classInstance = Activator.CreateInstance(type, null);

                if (parameters.Length == 0)
                {
                    result = methodInfo.Invoke(classInstance, null);
                }

                else
                {
                    object[] parametersArray = new object[] {p1, p2 };
                    result = methodInfo.Invoke(classInstance, parametersArray);
                }
            }

   
        }

        public static T Creator<T> () 
            where T : class, new()
        {
            return new T();
        }
    #endregion 

}

    #region classes
    public class Person
    {
        #region fields
        private int a = 5;
        public char f = 'u';
        public string name = "Aleksey";
        #endregion fields
        public string A()
        {
            return "This'is method A!!!";
        }
        public int MyMethods(int a, double b)
        {
            Console.WriteLine("\nФункция MyMethods вызвана!");
            return a+(int)b;
        }
        public int MyMethods1()
        {
            return 3;
        }
        protected String MyMethods2()
        {
            return "hello";
        }

        public Person()
        {
        }
    }

    interface Base
    {
        public int Foo(string mess);
    }

    public class Employee : Base
    {
        private int salary = 1500;
        public int Foo(string mess)
        {
            Console.WriteLine(mess);
            return salary;
        }

    }
    #endregion 
}
