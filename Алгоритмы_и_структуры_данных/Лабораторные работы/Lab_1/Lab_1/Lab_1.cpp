
/*�������� ��������� ������ �� ����� ������������������ �������� ��� ��������������
N ������ � i-�� �� k-�� �������� � ��������� �����. ������ ������ ������ �������� ��� �����
�� 4 ������ (N ������ = 4; k �������� = 3) ����� ��������� ���:
������������ ���� 4 � 1 �� 2 ���������
������������ ���� 3 � 1 �� 3 ���������
������������ ���� 4 � 2 �� 3 ���������
�
������������ ���� 1 � 3 �� 2 ���������
������������ ������������ ����������� ���������� N � k ����� ������� ������ ���������.*/

#include <iostream>
#include <Windows.h>
using namespace std;
void hanoi(int, int, int, int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int blocks, kernel_1, kernel_2, middle;

    cout << "������� ������� ������ ��� ����� ���������� �����\n";
    cout << "������� ���������� ������: ", cin >> blocks;
    cout << "������� �� ����� ������� ��������� ����� ����������: ", cin >> kernel_1;
    cout << "������� �� ����� ������� �� ������ ����������� �����: ", cin >> kernel_2;
   
    if (blocks == 1)
    {
        cout << "����������� ���� " << blocks << " c " << kernel_1 << " �� " << kernel_2 << " ��������\n";
    }

    if (blocks < 1) cout << "���������� ������������ ������� ���� ����!";
    middle = 6 - kernel_1 - kernel_2;
    
    hanoi(blocks, kernel_1, kernel_2, middle);
}

void hanoi(int blocks, int kernel_1, int kernel_2, int middle)
{
    if (blocks != 0)
    {
        hanoi(blocks - 1, kernel_1, middle, kernel_2);
        cout << "����������� ���� " << blocks << " c " << kernel_1 << " �� " << kernel_2 << " ��������\n";
        hanoi(blocks - 1, middle, kernel_2, kernel_1);
    }
}

