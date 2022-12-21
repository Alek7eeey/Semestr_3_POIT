#include "stdafx.h"

using namespace std;

void Serealizer::Invoke()
{
	file = ofstream("D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Лабораторные работы\\Lab_5\\Serealization\\Debug\\bin.txt");

	short strsize = strlen(data.String) + 1;

	file.clear();
	file.write(reinterpret_cast <char*> (&strsize), sizeof(short));
	file.write(data.String, sizeof(char) * strsize);
	file.write(reinterpret_cast <char*> (&data.Int), sizeof(int));
	file.close();
}
