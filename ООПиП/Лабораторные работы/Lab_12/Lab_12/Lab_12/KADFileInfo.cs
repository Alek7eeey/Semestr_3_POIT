using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Reflection;

namespace Lab_12
{
    class KADFileInfo
    {
        /*
          3. Создать класс XXXFileInfo c методами для вывода информации о конкретном файле 
            a. Полный путь 
            b. Размер, расширение, имя 
            c. Дата создания, изменения 
            d. Продемонстрируйте работу класса
         */

        #region methods
        static public void FullPathToFile(string nameFile)
        {
            if (nameFile is null)
            {
                throw new ArgumentNullException(nameof(nameFile));
            }

            FileInfo f = new (nameFile);
            Console.WriteLine("Путь к файлу: " + f.FullName);

            KADLog.Write("KADFileInfo", MethodBase.GetCurrentMethod()!.Name);
        }

        static public void GetSizeExtensionName(string nameCatalog)
        {
            if (nameCatalog is null)
            {
                throw new ArgumentNullException(nameof(nameCatalog));
            }
            /*DirectoryInfo di = new (nameCatalog);
            FileInfo[] fiArr = di.GetFiles();

            foreach (FileInfo f in fiArr)
            {
                if (f.Name == nameFile)
                {
                    Console.WriteLine("Размер файла {0} составляет {1} байтов.", f.Name, f.Length);
                }
            } */
            FileInfo file = new(nameCatalog);
            long size = file.Length;
            Console.WriteLine();
            Console.WriteLine("Размер файла: " + size);
            Console.WriteLine("Расширение файла: " + file.Extension);
            Console.WriteLine("Название файла: " + file.Name);
            
            KADLog.Write("KADFileInfo", MethodBase.GetCurrentMethod()!.Name);
        }

        static public void GetDateCreateAndChange(string nameFile)
        {
            if (nameFile is null)
            {
                throw new ArgumentNullException(nameof(nameFile));
            }

            DateTime fileCreatedDate = File.GetCreationTime(nameFile);
            Console.WriteLine();
            Console.WriteLine("Дата и время создания: " + fileCreatedDate);
            DateTime ChangeFile = File.GetLastWriteTime(nameFile);
            Console.WriteLine("Последнее изменение файла: " + ChangeFile);
            
            KADLog.Write("KADFileInfo", MethodBase.GetCurrentMethod()!.Name);
        }

        #endregion
    }
}
