#include "stdafx.h"

using namespace std;

int main() 
{
	Data data=Data();

	cout << "text: ";
	cin.getline(data.String, 150);

	cout << endl << "num:";
	cin >> data.Int;

	Serealizer serealizer (data);

	serealizer.Invoke();

	delete[] data.String;
	system("pause");
}