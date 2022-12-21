using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.IO.Compression;
using System.Net.Mime;
using System.Reflection;

namespace Lab_12
{
    class KADFileManager
    {
        /*
         5. Создать класс XXXFileManager. Набор методов определите самостоятельно. С его помощью выполнить следующие действия:
            a. Прочитать список файлов и папок заданного диска. Создать директорий XXXInspect, создать текстовый файл xxxdirinfo.txt и сохранить туда информацию.
               Создать копию файла и переименовать его. Удалить первоначальный файл.
            b. Создать еще один директорий XXXFiles. Скопировать в него все файлы с заданным расширением из заданного пользователем директория.
               Переместить XXXFiles в XXXInspect.
            c. Сделайте архив из файлов директория XXXFiles. Разархивируйте его в другой директорий.
         */

        static public void GetFileAndDir(string NameDisk)
        {
            if (NameDisk is null)
            {
                throw new ArgumentNullException(nameof(NameDisk));
            }

            DirectoryInfo di = new(NameDisk);
            FileInfo[] fiArr = di.GetFiles();
            Console.WriteLine();
            Console.WriteLine($"Файлы диска {NameDisk} :");

            foreach (FileInfo fi in fiArr)
                Console.WriteLine(fi);

            Console.WriteLine($"\nПапки диска {NameDisk} :");
            DirectoryInfo[] fiArr2 = di.GetDirectories();

            foreach (DirectoryInfo fi in fiArr2)
                Console.WriteLine(fi);

            KADLog.Write("KADFileManager", MethodBase.GetCurrentMethod()!.Name);
        }

        static public void CreateDirAndFile(string NameDir, string NameFile)
        {
            if (NameDir is null)
            {
                throw new ArgumentNullException(nameof(NameDir));
            }

            if (NameFile is null)
            {
                throw new ArgumentNullException(nameof(NameFile));
            }

            DirectoryInfo dirInfo = new(NameDir);

            if (!dirInfo.Exists)
            {
                dirInfo.Create();
            }

            using (StreamWriter writer = new(NameFile, false))
            {
                writer.WriteLine("Сохранённая информация)");
            }

            KADLog.Write("KADFileManager", MethodBase.GetCurrentMethod()!.Name);
        }

        static public void CopyFile(string pathFrom, string pathTo)
        {
            if (pathFrom is null)
            {
                throw new ArgumentNullException(nameof(pathFrom));
            }

            if (pathTo is null)
            {
                throw new ArgumentNullException(nameof(pathTo));
            }

            FileInfo fi = new(pathTo);

            if (!fi.Exists)
                File.Copy(pathFrom, pathTo);

            KADLog.Write("KADFileManager", MethodBase.GetCurrentMethod()!.Name);
        }

        static public void DelFile(string path)
        {
            if (path is null)
            {
                throw new ArgumentNullException(nameof(path));
            }

            FileInfo fi = new(path);

            if (fi.Exists)
            {
                File.Delete(path);
            }

            KADLog.Write("KADFileManager", MethodBase.GetCurrentMethod()!.Name);
        }

        static public void CreateDirAndCopyFile(string nameDir, string FileExtenshion, string pathFrom)
        {
            /*DirectoryInfo dirInfo = new(nameDir);

            if (!dirInfo.Exists)
            {
                dirInfo.Create();
            }

            FileInfo dirInfo2 = new(nameDir);

            if (!dirInfo2.Exists)
                File.Copy(pathFrom, nameDir);*/

            if (nameDir is null)
            {
                throw new ArgumentNullException(nameof(nameDir));
            }

            if (FileExtenshion is null)
            {
                throw new ArgumentNullException(nameof(FileExtenshion));
            }

            if (pathFrom is null)
            {
                throw new ArgumentNullException(nameof(pathFrom));
            }

            DirectoryInfo dirFrom = new(pathFrom);
            DirectoryInfo dirTo = new(nameDir);

            var files = dirFrom.GetFiles();

            foreach (FileInfo f in dirTo.GetFiles())
            {
                f.Delete();
            }

            foreach (var file in files)
            {

                if (FileExtenshion.Length == 0 ||
                    FileExtenshion.Contains(file.Extension))
                {
                    file.CopyTo(dirTo.FullName + "\\" + file.Name);
                }
            }

            KADLog.Write("KADFileManager", MethodBase.GetCurrentMethod()!.Name);

        }

        async static public void ArchiveFile(string pathF, string targetFolder)
        {
            if (pathF is null)
            {
                throw new ArgumentNullException(nameof(pathF));
            }

            if (targetFolder is null)
            {
                throw new ArgumentNullException(nameof(targetFolder));
            }
            
            DirectoryInfo dir = new(pathF);
            string path = $"{dir.FullName}//..//{dir.Name}.zip";

            if(!Directory.Exists(path))
            {
                Console.WriteLine("\nАрхив уже создан!");
            }
            else
            {
                ZipFile.CreateFromDirectory(dir.FullName, path);
            }

            try
            {
                ZipFile.ExtractToDirectory(path, targetFolder);
            }

            catch(Exception ex)
            {
                Console.WriteLine("Файлы уже разархивированы!\n");
            }


            KADLog.Write("KADFileManager", "Archive File");
        }

    }
}
