using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Reflection;

namespace Lab_12
{
    class KADDirInfo
    {
        /*
         4. Создать класс XXXDirInfo c методами для вывода информации о конкретном директории 
            a. Количестве файлов 
            b. Время создания 
            c. Количестве поддиректориев 
            d. Список родительских директориев 
            e. Продемонстрируйте работу класса
         */
        static public void GetCountOfFiles(string NameDir)
        {
            if (NameDir is null)
            {
                throw new ArgumentNullException(nameof(NameDir));
            }

            DirectoryInfo di = new (NameDir);
            FileInfo[] fiArr = di.GetFiles();
            Console.WriteLine();
            Console.WriteLine("Количество файлов: " + fiArr.Count());

            KADLog.Write("KADDirInfo", MethodBase.GetCurrentMethod()!.Name);
        }

        static public void GetTimeOfCreate(string nameDir)
        {
            if (nameDir is null)
            {
                throw new ArgumentNullException(nameof(nameDir));
            }

            DirectoryInfo di = new(nameDir);
            DateTime creationTime = Directory.GetCreationTime(nameDir);
            Console.WriteLine("Время и дата создания директория: " + creationTime);

            KADLog.Write("KADDirInfo", MethodBase.GetCurrentMethod()!.Name);
        }

        static public void GetCountOfSubDir(string pathToFile)
        {
            if (pathToFile is null)
            {
                throw new ArgumentNullException(nameof(pathToFile));
            }

            DirectoryInfo di = new(pathToFile);
            DirectoryInfo[] diArr = di.GetDirectories();

            Console.WriteLine("Количество поддиректориев: " + diArr.Count());

            KADLog.Write("KADDirInfo", MethodBase.GetCurrentMethod()!.Name);
        }

        static public void GetParentsDir(string pathToFile)
        {
            if (pathToFile is null)
            {
                throw new ArgumentNullException(nameof(pathToFile));
            }

            Console.WriteLine("Родительские директории: ");
            Console.WriteLine(Directory.GetParent(pathToFile));

            KADLog.Write("KADDirInfo", MethodBase.GetCurrentMethod()!.Name);
        }
    }
}
