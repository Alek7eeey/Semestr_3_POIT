using System;
using System.Reflection.PortableExecutable;
using System.Text;

namespace LAB2
{
    class PHONE
    {
        private readonly string ID;
        public static int count = 0;

        private string name;
        public string name_1
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }
        private string surname;
        public string surname_1
        {
            get
            {
                return surname;
            }
            set
            {
                surname = value;
            }
        }
        private string patronymic;
        public string patronymic_1
        {
            get
            {
                return patronymic;
            }
            set
            {
                patronymic = value;
            }
        }
        private string adress;
        public string Adress_1
        {
            get
            {
                return adress;
            }
            set
            {
                adress = value;
            }
        }

        public string Num_of_card_2 { get; set; }

        public int Debet;
        public int Debet_1
        {
            set
            {
               if (value < 0)
                {
                    Debet = -1;
                }

               else
                {
                    Debet = value;
                }

            }

            get
            {
                return Debet;
            }
        }

        private string credit;
        public string credit_1
        {
            set
            {
                try 
                {
                    int f = int.Parse(value);
                    if (f < 0)
                    {
                        credit = null;
                    }
                    else
                    {
                        credit = value;
                    }
                }

                catch
                {
                    credit = null;
                }

                    
            }
           
            get
            {
                return credit;
            }
        }

        
        private string time_calls_city;
        public string time_1
        {
            set
            {
                int f;
                if (!int.TryParse(value, out f))
                {
                    if (f < 0)
                    {
                        time_calls_city = null;
                    }
                    else
                    {
                        time_calls_city = value;
                    }
                }
            }

            get
            {
                return time_calls_city;
            }
        }
        private string time_talk_longdistance;
        public string time_2
        {
            set
            {
                int f;
                if (int.TryParse(value.Split(" ")[0], out f))
                {
                    if (f < 0)
                    {
                        time_talk_longdistance = null;
                    }
                    else
                    {
                        time_talk_longdistance = value;
                    }
                }
            }

            get
            {
                return time_talk_longdistance;
            }
        }
        static private string mark_of_phone;
        private const string country = "Belarus";

        public PHONE()
        {
            ID = Guid.NewGuid().ToString();
            name_1 = "-";
            surname_1 = "-";
            patronymic_1 = "-";
            Adress_1 = "-";
            Num_of_card_2 = "-";
            Debet_1 = 0;
            credit_1 = "0";
            time_1 = "0" + " минут(ы)";
            time_2 = "0" + " минут(ы)";
            count++;
        }

        public PHONE(string a, string n, string sn)
        {
            ID = Guid.NewGuid().ToString();
            name_1 = n;
            surname_1 = sn;
            patronymic_1 = "-";
            Adress_1 = "-";
            Num_of_card_2 = "-";
            Debet_1 = 0;
            credit_1 = a;
            time_1 = "0" + " минут(ы)";
            time_2 = "0" + " минут(ы)";
            count++;
        }

        public PHONE(int deb,string tcc = "23", string ptrn = "Aleksandrovich")
        {
            ID = Guid.NewGuid().ToString();
            name_1 = "-";
            surname_1 = "-";
            patronymic_1 = ptrn;
            Adress_1 = "-";
            Num_of_card_2 = "-";
            Debet_1 = deb;
            credit_1 = "0";
            time_1 = tcc + " минут(ы)";
            time_2 = "0" + " минут(ы)";
            count++;
        }

        static PHONE()
        {
            mark_of_phone = "iphone";
        }

        //private PHONE() { } //закрытый конструктор

        public static int Balance(ref int deb, ref int cred)
        {
            int ostatok = cred - deb;
            if (ostatok < 0)
            {
                Console.WriteLine("У вас минус на балансе!");
            }

            return ostatok;
        }

        public static void Information()
        {
            Console.WriteLine("Создано {0} объектов", PHONE.count);
        }

        static public int time_count_foo = 0;

        public static void MORE_THAN_SPECIFIED(string time, PHONE phone_1, int size)
        {
            int time_int = Convert.ToInt32(time);
            int time_count = 0;

            if (Convert.ToInt32(phone_1.time_1.Split(" ")[0]) > time_int)
            {
                Console.WriteLine("Имя: {0}", phone_1.name_1);
                Console.WriteLine("Фамилия: {0}", phone_1.surname_1);
                Console.WriteLine("Отчество: {0}", phone_1.patronymic_1);
                Console.WriteLine("Адрес: {0}", phone_1.Adress_1);
                Console.WriteLine("Номер карты: {0}", phone_1.Num_of_card_2);
                Console.WriteLine("Дебет: {0}", phone_1.Debet_1);
                Console.WriteLine("Кредит: {0}", phone_1.credit_1);
                Console.WriteLine("Время городских разговоров: {0}", phone_1.time_1);
                Console.WriteLine("Время междугородных разговоров: {0}", phone_1.time_2);
            }
            
            else
            {
                time_count_foo++;
            }

            if(time_count_foo == size)
            {
                Console.WriteLine("Такие абоненты отсутствуют!");
            }
        }

        public static void IS_USE(PHONE phone_1, int size)
        {
            
            if (Convert.ToInt32(phone_1.time_2.Split(" ")[0]) > 0)
            {
                Console.WriteLine("Имя: {0}", phone_1.name_1);
                Console.WriteLine("Фамилия: {0}", phone_1.surname_1);
                Console.WriteLine("Отчество: {0}", phone_1.patronymic_1);
                Console.WriteLine("Адрес: {0}", phone_1.Adress_1);
                Console.WriteLine("Номер карты: {0}", phone_1.Num_of_card_2);
                Console.WriteLine("Дебет: {0}", phone_1.Debet_1);
                Console.WriteLine("Кредит: {0}", phone_1.credit_1);
                Console.WriteLine("Время городских разговоров: {0}", phone_1.time_1);
                Console.WriteLine("Время междугородных разговоров: {0}", phone_1.time_2);
            }

            else
            {
                time_count_foo++;
            }

            if (time_count_foo == size)
            {
                Console.WriteLine("Такие абоненты отсутствуют!");
            }
        }

    }

  
    partial class MAIN_CLASS
    {
        static void Main(string[] args)
        {
            int size = 3;
            PHONE[] elements = new PHONE[size];
            PHONE Ph1 = new PHONE();
            PHONE Ph2 = new PHONE("10", "Aleksey", "Kravchenko");
            PHONE Ph3 = new PHONE(540);
            elements[0] = Ph1;
            elements[1] = Ph2;
            elements[2] = Ph3;

            int choice;
            while (true)
            {
                
                menu();
                Console.WriteLine("Выберите пункт:");
                choice = Convert.ToInt32(Console.ReadLine());


                switch (choice)
                {

                    case 1:
                        {
                            Console.Clear();
                            output(elements, size);
                            break;
                        }

                    case 2:
                        {
                            Console.Clear();
                            Console.WriteLine("Количество объектов: {0}", PHONE.count);
                            Console.WriteLine("\n");
                            break;
                        }

                    case 3:
                        {
                            Console.Clear();
                            Console.WriteLine("Введите значение: ");
                            string num = Console.ReadLine();
                            int co = 0;
                            while (co < size)
                            {
                                PHONE.MORE_THAN_SPECIFIED(num, elements[co], size);
                                co++;
                            }
                            PHONE.time_count_foo = 0;
                            break;
                        }

                    case 4:
                        {
                            Console.Clear();
                            int co = 0;
                            while (co < size)
                            {
                                PHONE.IS_USE(elements[co], size);
                                co++;
                            }
                            PHONE.time_count_foo = 0;
                            break;
                        }

                    case 5:
                        {
                            Console.Clear();
                            Console.WriteLine("Пока!");
                            Environment.Exit(1);
                            break;
                        }

                }
            }
        }
    }

    partial class MAIN_CLASS
    {
        public static void menu()
        {
            Console.WriteLine("Выберите операцию, которую необходимо выполнить:");
            Console.WriteLine("1) Вывод инфорамции.");
            Console.WriteLine("2) Получить информацию по количеству созданных объектов.");
            Console.WriteLine("3) Получить информацию про абонентов, у которых время внутригородских разговоров превышает заданное.");
            Console.WriteLine("4) Сведения об абонентах, которые пользовались междугородной связью.");
            Console.WriteLine("5)Выход");
        }

        public static void output(PHONE[] elements, int size) 
        {
            Console.WriteLine("Вывод инфнормации:");
            
            for(int i = 0; i < size; i++)
            {
                
                    Console.WriteLine("Имя: {0}", elements[i].name_1);
                    Console.WriteLine("Фамилия: {0}", elements[i].surname_1);
                    Console.WriteLine("Отчество: {0}", elements[i].patronymic_1);
                    Console.WriteLine("Адрес: {0}", elements[i].Adress_1);
                    Console.WriteLine("Номер карты: {0}", elements[i].Num_of_card_2);
               
                if (elements[i].Debet_1 == -1)
                {
                    Console.WriteLine("Дебет: некорректные данные");
                }
                else
                {
                    Console.WriteLine("Дебет: {0}", elements[i].Debet_1);
                }

                if (elements[i].credit_1 == null)
                {
                    Console.WriteLine("Кредит: некорректные данные!");
                }
                else 
                {
                    Console.WriteLine("Кредит: {0}", elements[i].credit_1);
                }

                if (elements[i].time_1 == null)
                {
                    Console.WriteLine("Время городских разговоров: некорректные данные");
                }
                else
                {
                    Console.WriteLine("Время городских разговоров: {0}", elements[i].time_1);
                }

                if (elements[i].time_2  == null)
                {
                    Console.WriteLine("Время междугородных разговоров: некорректные данные");
                }
                else
                {
                    Console.WriteLine("Время междугородных разговоров: {0}", elements[i].time_2);
                }
               
                Console.WriteLine("----------------------------------------------------");
            }
        }
    }
}
