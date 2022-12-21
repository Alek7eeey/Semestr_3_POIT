#include "stdafx.h"

using namespace std;

int main()
{
	Data data = Data();

	Serialize serealizer(data);

	serealizer.call();

	system("pause");
}