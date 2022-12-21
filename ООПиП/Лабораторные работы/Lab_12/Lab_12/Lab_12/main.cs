using Lab_12;
using System;
using System.Linq;
using System.Text;
using System.IO;


namespace Lab_12
{
    partial class Program
    {
        public static void Main(string[] argv)
        {
            KADLog.Write("Main", "begin");

            KADDiskInfo.GetInformationAboutDisks();
            KADFileInfo.FullPathToFile("D:\\studing\\TestFile.txt");
            KADFileInfo.GetSizeExtensionName("D:\\studing\\TestFile.txt");
            KADFileInfo.GetDateCreateAndChange("D:\\studing\\TestFile.txt");
            KADDirInfo.GetCountOfFiles("D:\\studing\\");
            KADDirInfo.GetTimeOfCreate("D:\\studing\\");
            KADDirInfo.GetCountOfSubDir("D:\\studing\\");
            KADDirInfo.GetParentsDir("D:\\studing\\");
            KADFileManager.GetFileAndDir("D:\\");
            KADFileManager.CreateDirAndFile("D:\\KADInspect", "D:\\KADInspect\\kaddirinfo.txt");
            KADFileManager.CopyFile("D:\\KADInspect\\kaddirinfo.txt", "D:\\KADInspect\\kaddirinfoCOPY.txt");
            //KADFileManager.DelFile("D:\\KADInspect\\kaddirinfo.txt");
            KADFileManager.CreateDirAndCopyFile("D:\\KADFiles", ".txt", "D:\\studing");
            KADFileManager.ArchiveFile("D:\\KADFiles", "D:\\KADInspect");

            KADLog.Write("Main\n\n", "end");

            Console.ReadLine();
            Console.Clear();
            Console.WriteLine("Информация из файла:\n");
            KADLog.ReadAndFind("23.10.2022","11:46:47", "12:00:30");
           // KADLog.DeleteInfPerHour();
        }
    }
}
