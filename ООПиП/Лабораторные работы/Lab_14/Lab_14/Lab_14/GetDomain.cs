using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Loader;
using System.IO;

namespace Lab_14
{
    static class GetDomain
    {
        public static void GetInfoDomain()
        {
            AppDomain domain = AppDomain.CurrentDomain;
            Console.WriteLine($"Имя: {domain.FriendlyName}");
            Console.WriteLine($"Базовый директорий: {domain.BaseDirectory}");
            Console.WriteLine($"Текущая конфигурация: {domain.SetupInformation}");
            Console.WriteLine();
            Console.WriteLine("Все сборки:");
            Assembly[] assemblies = domain.GetAssemblies();
            foreach (Assembly asm in assemblies)
            {
                Console.WriteLine(asm.GetName().Name);
            }
        }

        //УСТАРЕВШЕЕ, УЖЕ НЕ ПОДДЕРЖИВАЕТСЯ((
        public static void CreateDomain()
        {
            try
            {
                AppDomain newDomain = AppDomain.CreateDomain("NewDomain");
                newDomain.Load(newDomain.BaseDirectory);
                Console.WriteLine("Название: " + newDomain.FriendlyName);
                AppDomain.Unload(newDomain);
            }
            
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
