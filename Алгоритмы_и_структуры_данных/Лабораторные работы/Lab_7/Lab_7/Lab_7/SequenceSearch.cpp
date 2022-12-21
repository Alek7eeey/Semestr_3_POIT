#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void main()
{
	/*setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int count = 1;
	int biggestCount = 1;
	int presentValue = 0;
	int presentValue2 = 0;
	int elStartLongestCombination = 0;
	int	N;
	cout << "Введите N:", cin >> N;

	auto arr = new int[N];

	cout << "Последовательность: " << endl;
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}

	for (int i = 0; i < N; i++)
	{
		presentValue = i;
		presentValue2 = i;
		for (int j = i+1; j < N; j++)
		{
			if (arr[presentValue] < arr[j])
			{
				count++;
				presentValue = j;
			}
			if (N == j+1)
			{
				if(count> biggestCount)
				{
					elStartLongestCombination = presentValue2;
					biggestCount = count;
				}
			}
		}
		count = 1;
	}
	char* longestSequence = new char[count];

	cout << "\nДлина максимальной последовательности: " << biggestCount << endl;

	cout <<'\n' << arr[elStartLongestCombination]<< ' ';
	for (int j = elStartLongestCombination+1; j < N; j++)
	{
		if (arr[elStartLongestCombination] < arr[j])
		{
			cout << arr[j]<<' ';
			elStartLongestCombination = j;
		}
	}

	delete[] longestSequence, delete[] arr;*/

	    srand(time(NULL));
		int N;
		cin >> N;
		int* arr = new int[N];
		int* lenghts = new int[N];
		int* path = new int[N];

		for (int i = 0; i < N; i++)
		{
			lenghts[i] = 1;
			path[i] = -1;
		}

		for (int i = 0; i < N; i++)
		{
			arr[i] = 1 + rand() % 20; 
			//cin >> arr[i]; 1728 3456
			cout << arr[i] << " ";

		}
		cout << endl;


		for (int j = 1; j < N; j++) {
			for (int k = 0; k < j; k++) {
				if (arr[j] > arr[k])
				{
					if (lenghts[j] <= lenghts[k])
					{
						lenghts[j] = lenghts[k] + 1;
						path[j] = k;
					}
				}
			}
		}

		int max = 0;
		int check = 0;
		for (int i = 0; i < N; i++)
		{
			if (lenghts[i] > max)
			{
				check = i;
				max = lenghts[i];
			}
		}
		cout << max << endl;


		for (int i = 0; i < N; i++)
		{
			cout << lenghts[i] << " ";
		}
		cout << endl;


		for (int i = 0; i < N; i++)
		{
			cout << path[i] << " ";
		}
		cout << endl;


		int out[100];
		for (int i = max; i >= 0; i--)
		{

			out[i] = arr[check];
			check = path[check];
		}
		for (int i = 1; i < max + 1; i++)
		{
			cout << out[i] << " ";
		}

		delete[] arr;
		delete[] lenghts;
		delete[] path;
	}