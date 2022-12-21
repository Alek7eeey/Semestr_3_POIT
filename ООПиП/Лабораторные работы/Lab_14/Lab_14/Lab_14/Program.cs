using System;
using System.Collections;
using System.Threading;
using System.Diagnostics;

namespace Lab_14
{
    class Program
    {
        public static void Main(string[] argv)
        {
            #region Process
            Console.WriteLine("---------------------- EX 1 ----------------------\n");
            GetProcess.GetAllProcess();
            #endregion

            #region Domain
            Console.WriteLine("\n---------------------- EX 2 ----------------------\n");
            GetDomain.GetInfoDomain();
     
            Console.WriteLine("");
            GetDomain.CreateDomain();
            #endregion

            #region NewThread
            Console.WriteLine("\n---------------------- EX 3 ----------------------");
            int n = Convert.ToInt32(Console.ReadLine());
            NewThread.CreateThread(n);
            #endregion

            #region TwoThread
            TwoThread.mutexObj.WaitOne();
            Console.WriteLine("\n---------------------- EX 4 ----------------------");
            int k = Convert.ToInt32(Console.ReadLine());
            TwoThread.CreateThread(k);
            TwoThread.mutexObj.ReleaseMutex();


            OutputSequence._OutputSequence(100);
            #endregion

            #region timer
            TwoThread.mutexObj.WaitOne();
            Thread.Sleep(100);
            timer._timer();
            TwoThread.mutexObj.ReleaseMutex();
            #endregion

        }
    }
}