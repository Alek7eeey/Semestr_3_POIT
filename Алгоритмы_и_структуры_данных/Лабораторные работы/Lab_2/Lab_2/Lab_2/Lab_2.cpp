#include <iostream>
#include <queue>

using namespace std;

const int n = 10;
bool* visited = new bool[n];

//матрица смежности графа
int graph[n][n] =
{
{0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
{1, 0, 0, 0, 0, 1, 0, 0, 0, 0}, 
{0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
{0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
{0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
};
//поиск в глубину
void DFS(int st)
{
	cout << st + 1 << " ";
	visited[st] = true;
	
	for (int r = 0; r <= n; r++) {
		if ((graph[st][r] != 0) && (!visited[r]))
			DFS(r);
	}
}

//поиск в ширину
void BFS(int start)
{
	queue <int> q; // очередь для хранения номеров вершин
	bool visited[n]; //false - вершина не рассмотрена, true - рассмотрена
	bool inqueue[n]; //false - вершина не в очереди, true - в очереди
	int view_cell; // номер посещаемой вершины

	for (int i = 0; i < n; i++)
	{
		visited[i] = inqueue[i] = false;
	}

	q.push(start); // записываем начальную вершину в очередь
	visited[start] = inqueue[start] = true; //рассмотрели первую вершину
	
	while (!q.empty())
	{
		view_cell = q.front(); //обращение к первому элементу очереди
		cout << view_cell + 1 << " ";

		visited[view_cell] = true;
		q.pop();

		for (int i = 0; i < n; i++)
		{
			if (!inqueue[i] && graph[view_cell][i])
			{
				q.push(i);
				inqueue[i] = true;
			}
		}
	}
}


//главная функция
void main()
{
	setlocale(LC_ALL, "Rus");
	int start;
	cout << "Матрица смежности графа: " << endl;
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;

		for (int j = 0; j < n; j++)
			cout << " " << graph[i][j];
		cout << endl;
	}

	//список ребер (1,2)(2,1)
	cout << "\n-----------------------------" << endl;
	cout << "\nСписок рёбер: " << endl;
	int arr_1[11] = { 1,1,2,2,3,4,4,5,6,7,9 };
	int arr_2[11] = { 2,5,7,8,8,6,9,6,9,8,10 };

	for (int i = 0; i < n; i++)
	{
		cout << '{' << arr_1[i] << ", " << arr_2[i] << '}';
		cout << " {" << arr_2[i] << ", " << arr_1[i] << '}' << endl;
	}

	//список смежности 1->(2,3)...
	cout << "\n-----------------------------" << endl;
	cout << "\nСписок смежности: " << endl;
	int arrEdges[10][10] =
	{   {2,5},
		{7,8},
		{8},
		{6,9},
		{1,6},
		{4,5,9},
		{2,8},
		{2,3,7},
		{4,6,10},
		{9}
	};

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "->";

		for (int j = 0; j < n; j++)
		{
			if (arrEdges[i][j] == 0)
			{
				break;
			}
			cout << arrEdges[i][j] << " ";
		}
		cout <<endl;
	}
	cout << endl;
	system("pause");

	//поиск в глубину
	cout << "\n" << endl;
	cout << "Поиск в глубину" << endl;
	cout << "Стартовая вершина >> "; cin >> start;
	//массив посещенных вершин
	cout << "Порядок обхода: ";
	DFS(start - 1);

	//поиск в ширину
	cout << "\n" << endl;
	int start_2;
	cout << "\nПоиск в ширину" << endl;
	cout << "Стартовая вершина >> "; cin >> start_2;
	cout << "Порядок обхода: ";
	BFS(start_2 - 1);

	delete[]visited;
	cout << endl;
}