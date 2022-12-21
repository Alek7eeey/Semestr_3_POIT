using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics.Metrics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_15
{
    public static class Trade
    {
        private static int count = 0;
        public static async Task TaskAsync()
        {
            Products[] ProductssArr = new Products[15];

            for (int i = 0; i < 15; i++)
            {
                    ProductssArr[i] = new Products(i + 10, "Товар " + i);
            }

            using (BlockingCollection<Products> Productss = new BlockingCollection<Products>())
            {
                Task treader1 = new(() =>
                {
                    while (count < 15)
                    {
                        Console.WriteLine("Поставщик 1: " + ProductssArr[count].ToString());
                        Productss.Add(ProductssArr[count]);
                        count++;
                        Thread.Sleep(70);
                    }
                    Productss.CompleteAdding();

                });

                Task treader2 = new(() =>
                {
                    while (count < 15)
                    {
                        Console.WriteLine("Поставщик 2: " + ProductssArr[count].ToString());
                        Productss.Add(ProductssArr[count]);
                        count++;
                        Thread.Sleep(320);
                    }
                    Productss.CompleteAdding();

                });

                Task treader3 = new(() =>
                {
                    while (count < 15)
                    {
                        Console.WriteLine("Поставщик 3: " + ProductssArr[count].ToString());
                        Productss.Add(ProductssArr[count]);
                        count++;
                        Thread.Sleep(117);
                    }
                    Productss.CompleteAdding();

                });

                Task customer1 = new(() =>
                {

                    while (true)
                    {
                        Console.WriteLine("Покупатель1" + Productss.Take().ToString());
                        Thread.Sleep(80);
                        if (Productss.Count == 0)
                        {

                            Console.WriteLine("Покупатель 1 ушел(((");
                            break;
                        }
                    }
                });

                Task customer2 = new(() =>
                {

                    while (true)
                    {
                        Console.WriteLine("Покупатель2" + Productss.Take().ToString());
                        Thread.Sleep(110);
                        if (Productss.Count == 0)
                        {

                            Console.WriteLine("Покупатель 2 ушел(((");
                            break;
                        }
                    }
                });

                Task customer3 = new(() =>
                {
                    while (true)
                    {
                        Console.WriteLine("Покупатель3" + Productss.Take().ToString());
                        Thread.Sleep(140);
                        if (Productss.Count == 0)
                        {

                            Console.WriteLine("Покупатель 3 ушел(((");
                            break;
                        }
                    }

                });

                Task customer4 = new(() =>
                {

                    while (true)
                    {
                        Console.WriteLine("Покупатель4" + Productss.Take().ToString());
                        Thread.Sleep(50);
                        if (Productss.Count == 0)
                        {
                            Console.WriteLine("Покупатель 4 ушел(((");
                            break;
                        }
                    }

                });

                Task customer5 = new(() =>
                {

                    while (true)
                    {
                        Console.WriteLine("Покупатель5" + Productss.Take().ToString());
                        Thread.Sleep(170);
                        if (Productss.Count == 0)
                        {
                            Console.WriteLine("Покупатель 5 ушел(((");
                            break;
                        }
                    }

                });

                Task customer6 = new(() =>
                {

                    while (true)
                    {
                        Console.WriteLine("Покупатель6" + Productss.Take().ToString());
                        Thread.Sleep(150);
                        if (Productss.Count == 0)
                        {
                            Console.WriteLine("Покупатель 6 ушел(((");
                            break;
                        }
                    }

                });


                treader1.Start();
                Thread.Sleep(13);
                treader2.Start();
                Thread.Sleep(7);
                treader3.Start();

                customer1.Start();
                customer2.Start();
                customer6.Start();
                customer4.Start();
                customer3.Start();
                customer5.Start();


                await Task.WhenAll(treader1, treader2, treader3, customer1, customer2, customer3, customer4, customer5, customer6);

            }
        }
        public class Products
        {
            private int cost;
            private string name;

            public int Cost
            {
                get { return cost; }
                set
                {
                    if (value > 0 && value < 1000) cost = value;
                }
            }
            public string Name
            {
                get { return name; }
                set
                {
                    if (value.Length < 10 && value != null) name = value;
                }
            }

            public Products(int cost, string name)
            {
                this.Cost = cost;
                this.Name = name;
            }

            public override string ToString()
            {
                return "Товар: " + name + " цена: " + cost;
            }
        }
    }
}
