using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Reflection;

namespace Lab_12
{
    /*2. Создать класс XXXDiskInfo c методами для вывода информации о
    a.свободном месте на диске
    b. Файловой системе
    c.Для каждого существующего диска - имя, объем, доступный
    объем, метка тома.
    d.Продемонстрируйте работу класса*/
    class KADDiskInfo
    {
        public static void GetInformationAboutDisks()
        {
            DriveInfo[] drives = DriveInfo.GetDrives();

            foreach (DriveInfo drive in drives)
            {
                Console.WriteLine($"Название: {drive.Name}");
                Console.WriteLine($"Тип: {drive.DriveType}");
                if (drive.IsReady)
                {
                    Console.WriteLine($"Объем диска: {drive.TotalSize}");
                    Console.WriteLine($"Свободное пространство: {drive.TotalFreeSpace}");
                    Console.WriteLine($"Метка диска: {drive.VolumeLabel}");
                }
                Console.WriteLine();
            }

            KADLog.Write("KADDiskInfo", MethodBase.GetCurrentMethod()!.Name);
        }
    }
}
