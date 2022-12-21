
/*Написать программу вывода на экран последовательности действий для перекладывания
N дисков с i-го на k-ый стержень в ханойской башне. Пример вывода одного действия для башни
из 4 дисков (N дисков = 4; k стержней = 3) может выглядеть так:
«Переместить диск 4 с 1 на 2 стержень»
«Переместить диск 3 с 1 на 3 стержень»
«Переместить диск 4 с 2 на 3 стержень»
…
«Переместить диск 1 с 3 на 2 стержень»
Пользователю предоставить возможность определять N и k перед началом работы алгоритма.*/

#include <iostream>
#include <Windows.h>
using namespace std;
void hanoi(int, int, int, int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int blocks, kernel_1, kernel_2, middle;

    cout << "Введите входные данные для вашей ханнойской башни\n";
    cout << "Введите количество дисков: ", cin >> blocks;
    cout << "введите на каком стержне находится башня изначально: ", cin >> kernel_1;
    cout << "Введите на какой стержне вы хотите переместить башню: ", cin >> kernel_2;
   
    if (blocks == 1)
    {
        cout << "Переместить диск " << blocks << " c " << kernel_1 << " на " << kernel_2 << " стержень\n";
    }

    if (blocks < 1) cout << "Необходимо использовать минимум один диск!";
    middle = 6 - kernel_1 - kernel_2;
    
    hanoi(blocks, kernel_1, kernel_2, middle);
}

void hanoi(int blocks, int kernel_1, int kernel_2, int middle)
{
    if (blocks != 0)
    {
        hanoi(blocks - 1, kernel_1, middle, kernel_2);
        cout << "Переместить диск " << blocks << " c " << kernel_1 << " на " << kernel_2 << " стержень\n";
        hanoi(blocks - 1, middle, kernel_2, kernel_1);
    }
}

