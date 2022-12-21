using LAB_4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Lab_04
{
    class Program
    {
        public static void Main(string[] argv)
        {
            ADVERTISING advertising = new("11:30", "1.30 часа", "14+", "Беларусь", "Гай Ричи");
            advertising.ToString();
            Console.WriteLine("-----------------------------------");

            ART_FILMS art_films = new("12:30", "2 часа", "12+", "Беларусь");
            art_films.ToString();
            Console.WriteLine("-----------------------------------");
            
            CARTOONS cartoons = new("09:30", "30 минут", "6+", "Украина");
            cartoons.ToString();
            Console.WriteLine("-----------------------------------");

            FILM film = new("11:20", "3:30 часа", "16+", "Беларусь");
            film.ToString();
            Console.WriteLine("-----------------------------------");

            NEWS news = new("20:30", "20 минут", "14+", "Беларусь");
            news.ToString();
            Console.WriteLine("-----------------------------------");

            Console.WriteLine("\nИнформация про режиссера и главного героя:\n");
            PRODUCER producer = new("Ридли Скотт", "84 года", "Британия");
            producer.ToString();
            Console.WriteLine("-----------------------------------");

            MAIN_CHARACTER main_character = new("Уил Смит", "53 года", "США");
            main_character.ToString();

            Console.WriteLine("\n\n----------Printer-----------\n\n");

            Printer Printer = new();
            var programTV = new TV_program[]
            {
            advertising,
            art_films,
            cartoons,
            film,
            news
            };

            foreach (var El in programTV)
            {
                Printer.IAmPrinting(El);
            }


        }
    }
}
