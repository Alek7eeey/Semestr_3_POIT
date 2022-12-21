#include "stdafx.h"
#include <stdlib.h>
#include <string>
using namespace std;


void Serialize::call()
{
	file = ofstream("D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Лабораторные работы\\Lab_5(n)\\Lab_5\\Debug\\bin.txt");

	short strsize = wcslen(data.WcharVal) + 1;
    size_t convertedChars = 0;

    const size_t newsize = strsize * 2;
    char* nstring = new char[newsize];

    wcstombs_s(&convertedChars, nstring, newsize, data.WcharVal, _TRUNCATE);

	file.clear();
	file.write(reinterpret_cast <char*> (&strsize), sizeof(short));
	file.write(nstring, sizeof(char) * strsize);
	file.write(reinterpret_cast <char*> (&data.IntNum), sizeof(int));
	file.close();
}
