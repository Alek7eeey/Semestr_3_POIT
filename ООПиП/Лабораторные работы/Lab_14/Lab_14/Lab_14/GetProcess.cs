using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Lab_14
{
    static public class GetProcess
    {
        public static void GetAllProcess()
        {
            var process = Process.GetCurrentProcess();
            Console.WriteLine($"Текущий процесс:\nID: {process.Id} Имя: {process.ProcessName}  Используемая виртуальная память: {process.VirtualMemorySize64}");
            Console.WriteLine($"---------------------------");

            foreach (Process proces in Process.GetProcesses())
                {
                try
                {
                    // выводим id и имя процесса
                    Console.WriteLine($"ID: {proces.Id}  Имя: {proces.ProcessName}  Приоритет: {proces.BasePriority}  Время: {proces.StartTime}  " +
                        $"Общее время использования: {proces.UserProcessorTime}");
                }
                catch(Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }
                }
            }
        }
    }

