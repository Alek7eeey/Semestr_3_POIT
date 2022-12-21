#include <iostream>
#include <cstring>
using namespace std;
#define V 8

int G[V][V] = {
    {0, 2, 0, 8, 2, 0, 0, 0},
    {2, 0, 3, 10, 5, 0, 0, 0},
    {0, 3, 0, 0, 12, 0, 0, 7},
    {8, 10, 0, 0, 14, 3, 1, 0},
    {2, 5, 12, 14, 0, 11, 4, 8},
    {0, 0, 0, 3, 11, 0, 6, 0},
    {0, 0, 0, 1, 4, 6, 0, 9},
    {0, 0, 7, 0, 8, 0, 9, 0}
};

void Prim() {
    int min = INT_MAX;
    int amount_edge = 0;            // number of edge
    int row = 0;
    int col = 0;

    int selected[V];

    for (int i = 0; i < V; i++) 
    {
        selected[i] = false;
    }

    for (int i = 0; i < V; i++) { //находим мин элемент во всей матрице с этого столбца и строки будет рассмотрение 
        for (int j = 0; j < V; j++) {
            if (G[i][j] < min)
                min = G[i][j];
        }
    }
    selected[min] = true;  //для мин          
    cout << "Edge" << " : " << "Weight";
    cout << endl;
    while (amount_edge < V - 1) {
        min = INT_MAX;


        for (int i = 0; i < V; i++) {
            if (selected[i]) { //если столбец тру мы его рассматриваем и ищем там минимальные 
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) { // если строка не вычеркнута 
                        if (min > G[i][j]) {
                            min = G[i][j];
                            row = i;
                            col = j;
                        }

                    }
                }
            }
        }
        cout << (row + 1) << " - " << col + 1 << " :  " << G[row][col];
        cout << endl;
        selected[col] = true;
        amount_edge++;
    }

}

int main() {
    cout << "Algorithm Prima\n";
    Prim();
}