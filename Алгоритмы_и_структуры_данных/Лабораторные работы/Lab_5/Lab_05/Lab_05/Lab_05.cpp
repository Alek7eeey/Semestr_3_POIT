#include <Windows.h>
#include <iostream>
using namespace std;

void PrimaFunct();
void Kraskl();
int interconnected(int i);
void unionCompos(int i, int j);

const int Y = 8;
int infCost = 10000;
int visited[Y];

int Matrix[8][8] =
{
    {0, 2, 0, 8, 2, 0, 0, 0 },
    {2, 0, 3, 10, 5, 0, 0, 0},
    {0, 3, 0, 0, 12, 0, 0, 7},
    {8, 10, 0, 0, 14, 3, 1, 0},
    {2, 5, 12, 14, 0, 11, 4, 8},
    {0, 0, 0, 3, 11, 0, 6, 0},
    {0, 0, 0, 1, 4, 6, 0, 9},
    {0, 0, 7, 0, 8, 0, 9, 0}
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PrimaFunct();
    Kraskl();
}

void PrimaFunct()
{
    cout << "Метод прима: \n";
    bool visited[8];
    for (int i = 0; i < 8; i++)
    {
        visited[i] = false;
    }
    visited[0] = true;

    for (int l = 0; l < 7; l++) {
        int minHor = infCost;
        int minVer = infCost;
        for (int i = 0; i < 8; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < 8; j++)
                {
                    if (!visited[j] && Matrix[i][j] > 0 && (minVer == infCost || Matrix[i][j] < Matrix[minVer][minHor]))
                    {
                        minVer = i, minHor = j;
                    }
                }
            }
        }
        visited[minHor] = true;
        cout << minVer + 1 << ' ' << minHor + 1 << endl;
    }
    cout << "\n\n";
}

void Kraskl()
{
    int min;
    int edgesCount = 0;
    for (int i = 0; i < Y; i++)
    {
        visited[i] = i;
    }

    while (edgesCount < Y - 1)
    {
        min = infCost;
        int a = infCost, b = infCost;
        for (int i = 0; i < Y; i++)
        {
            for (int j = 0; j < Y; j++)
            {
                if (interconnected(i) != interconnected(j) && Matrix[i][j] < min && Matrix[i][j] != 0)
                {
                    min = Matrix[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        unionCompos(a, b);
        edgesCount++;
        cout << a + 1 << "---" << b + 1 << endl;
    }
}

int interconnected(int i)
{
    while (visited[i] != i)
    {
        i = visited[i];
    }
    return i;
}

void unionCompos(int i, int j)
{
    int a = interconnected(i);
    int b = interconnected(j);
    visited[a] = b;
}
