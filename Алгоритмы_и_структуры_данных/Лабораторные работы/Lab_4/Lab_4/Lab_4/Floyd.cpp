#include <iostream>
using namespace std;
const int maxV = 1000;


const int V = 6;
int C[V][V];
int D[V][V] = 
{
		   {0, 28, 21, 59, 12, 27},
		   {7, 0, 24, INT_MAX, 21, 9},
		   {9, 32, 0, 13, 11, INT_MAX},
		   {8, INT_MAX, 5, 0, 16, INT_MAX},
		   {14, 13, 15, 10, 0, 22},
		   {15, 18, INT_MAX, INT_MAX, 6, 0}
};
//алгоритм Флойда-Уоршелла
void FU()
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (i == j)
			{
				D[i][j] = 0;
				C[i][j] = 0;
			}
			else
			{
				C[i][j] = j + 1;
			}
		}
	}

	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (D[i][k] + D[k][j] < D[i][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					C[i][j] = C[i][k];
				}
			}
		}
	}


	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++) cout << D[i][j] << "\t";
		cout << endl;
	}

	cout << "Матрица последовательности вершин: " << endl;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++) cout << C[i][j] << "\t";
		cout << endl;
	}
}
//главная функция
void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Матрица кратчайших путей:" << endl;
	FU();
}
//#include<iostream>
//using namespace std;
//void main() {
//	setlocale(LC_CTYPE, "ru");
//	int matrixOfWeight[6][6] = {
//		{0,28,21,59,12,27},
//		{7,0,24,INT_MAX,21,9},
//		{9,32,0,13,11,INT_MAX},
//		{8,INT_MAX,5,0,16,INT_MAX},
//		{14,13,15,10,0,22},
//		{15,18,INT_MAX,INT_MAX,6,0},
//	};
//	int matrixOfPass[6][6];
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 6; j++)
//		{
//			if (i == j) {
//				matrixOfPass[i][j] = 0;
//				continue;
//			}
//			matrixOfPass[i][j] = j + 1;
//		}
//	}
//	int Sum;
//	for (int k = 0; k < 6; k++)
//	{
//		for (int i = 0; i < 6; i++)
//		{
//			for (int j = 0; j < 6; j++)
//			{
//				Sum = matrixOfWeight[i][k] + matrixOfWeight[k][j];
//				if (Sum < matrixOfWeight[i][j])
//				{
//					matrixOfWeight[i][j] = Sum;
//					matrixOfPass[i][j] = k + 1;
//				}
//			}
//		}
//	}
//	cout << "Матрица D:\n";
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 6; j++)
//		{
//			cout << matrixOfWeight[i][j] << "\t";
//		}
//		cout << '\n';
//	}
//	cout << "Матрица S:\n";
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 6; j++)
//		{
//			cout << matrixOfPass[i][j] << "\t";
//		}
//		cout << '\n';
//	}
//}