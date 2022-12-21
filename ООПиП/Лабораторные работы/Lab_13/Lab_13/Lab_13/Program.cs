using System;
using System.Collections;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Soap;
using System.Text.Json;
using System.Text.Json.Serialization;
using Newtonsoft.Json;
using System.Xml.Serialization;
using System.Xml;
using System.Xml.Linq;

namespace Lab_13
{
    class Program
    {
         public static void Main(string[] argv)
        {
           //Ex1
            CARTOONS shrek = new ("12:00", "Шрэк", "7+", "США");
            CARTOONS TomAndJery = new ("11:00", "Том и Джери", "7+", "США");
            CARTOONS IceAge = new("10:00", "Ледниковый период", "6+", "США");
            CARTOONS pivosaurics = new("22:00", "Пивозаврики", "10+", "Russia");
            CARTOONS[] cartoons = new[] { shrek, TomAndJery, IceAge, pivosaurics };

            #region binary

            BinaryFormatter BForm = new();
            Console.WriteLine("---------------- BINARY ------------------");
            using (FileStream fs = new ("Shrek.dat", FileMode.OpenOrCreate))
            {
                BForm.Serialize(fs, shrek);
                Console.WriteLine("Объект сериализован");
            }
            
            using (FileStream fs = new ("Shrek.dat", FileMode.OpenOrCreate))
            {
                CARTOONS newCartoon = (CARTOONS)BForm.Deserialize(fs);

                Console.WriteLine("Объект десериализован:");
                Console.WriteLine(newCartoon.ToString());
            }
            #endregion

            #region SOAP
            Console.WriteLine("----------------- SOAP -------------------");

            SoapFormatter formatter = new();

            using (FileStream fs = new ("cartoons.soap", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, cartoons);

                Console.WriteLine("Объект сериализован");
            }

            using (FileStream fs = new ("cartoons.soap", FileMode.OpenOrCreate))
            {
                CARTOONS[] newCartoon2 = (CARTOONS[])formatter.Deserialize(fs);

                Console.WriteLine("Объект десериализован:");
               
                foreach (CARTOONS p in newCartoon2)
                {
                    Console.WriteLine("Имя: {0}", p._name);
                }
            }
            #endregion

            #region JSON
            Console.WriteLine("\n----------------- JSON -------------------");

             string fileName = "IceAge.json";
             string json = JsonConvert.SerializeObject(IceAge);
             Console.WriteLine("Объект сериализован!");
             File.WriteAllText(fileName, json);
             Console.WriteLine("Объект десериализован:");
             var data = JsonConvert.DeserializeObject<CARTOONS>(json);
             Console.WriteLine("Название: " + data._name);

            /*
              string fileName = "shrek.json";
             string json = JsonSerializer.Serialize(shrek);
             Console.WriteLine("Объект сериализован!");
             File.WriteAllText(fileName, json);
             Console.WriteLine(File.ReadAllText(fileName));
            //!!!при таком варианте не работает десериализация
            //CARTOONS? cart = JsonSerializer.Deserialize<CARTOONS>(json);*/
            #endregion

            #region XML
            Console.WriteLine("\n----------------- XML --------------------");
            
            XmlSerializer xmlSerializer = new (typeof(CARTOONS));

            using (FileStream fs = new ("pivosaurics.xml", FileMode.OpenOrCreate))
            {
                xmlSerializer.Serialize(fs, pivosaurics);

                Console.WriteLine("Объект сериализован!");
            }

            using (FileStream fs = new ("pivosaurics.xml", FileMode.OpenOrCreate))
            {
                CARTOONS? newCart = xmlSerializer.Deserialize(fs) as CARTOONS;
                Console.WriteLine("Объект десериализован:");
                Console.WriteLine($"Название: {newCart?._name}  ");
            }
            #endregion

            #region requestToXml
            Console.WriteLine("\n---------------- request ------------------");

            XmlDocument xDoc = new();
            xDoc.Load("pivosaurics.xml");
            XmlElement? xRoot = xDoc.DocumentElement;

            XmlNodeList? nodes = xRoot?.SelectNodes("*");
            if (nodes is not null)
            {
                foreach (XmlNode node in nodes)
                    Console.WriteLine(node.OuterXml);
            }

            Console.WriteLine("\n--- 2 ---");

            XmlDocument xDoc2 = new ();
            xDoc.Load("pivosaurics.xml");
            XmlElement? xRoot2 = xDoc.DocumentElement;

            XmlNodeList? companyNodes = xRoot?.SelectNodes("//_name");
            if (companyNodes is not null)
            {
                foreach (XmlNode node in companyNodes)
                    Console.WriteLine(node.InnerText);
            }
            #endregion

            #region LinqToXML
            XDocument xdoc = new();

            XElement C = new ("cartoon");
            XAttribute NameAttr = new("name", "Tom & Jery");

            XElement CountryElem = new ("country", "USA");
            XElement TimeElem = new ("StartTime", "11:00");

            // добавляем атрибут и элементы в первый элемент person
            C.Add(NameAttr);
            C.Add(CountryElem);
            C.Add(TimeElem);

            XElement C2 = new XElement("cartoon");
            XAttribute с2NameAttr = new XAttribute("name", "Shrek");

            XElement c2CountryElem = new XElement("country", "USA");
            XElement c2TimeElem = new XElement("StartTime", "15:00");

            C2.Add(NameAttr);
            C2.Add(c2CountryElem);
            C2.Add(c2TimeElem);

            // создаем корневой элемент
            XElement people = new ("TV_PROGRAM");

            people.Add(C);
            people.Add(C2);
            // добавляем корневой элемент в документ
            xdoc.Add(people);

            xdoc.Save("cartoon.xml");
            #endregion
        }
    }
}
