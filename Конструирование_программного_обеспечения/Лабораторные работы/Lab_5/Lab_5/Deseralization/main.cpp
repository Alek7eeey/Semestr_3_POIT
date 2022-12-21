#include "Stdafx.h"
using namespace std;

int main()
{
	Data data;
	Deserializer deserializer(&data);
	deserializer.call();
	AsmConvenrter assembler(data);
	assembler.call();
}

void Deserializer::call() {

	file = ifstream("D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Лабораторные работы\\Lab_5(n)\\Serealization\\Debug\\bin.txt");

	short strsize = wcslen(data->WcharVal) + 1;
	size_t convertedChars = 0;

	const size_t newsize = strsize * 2;
	char* nstring = new char[newsize];

	wcstombs_s(&convertedChars, nstring, newsize, data->WcharVal, _TRUNCATE);

	file.clear();

	file.read(reinterpret_cast <char*> (&strsize), sizeof(short));
	file.read(nstring, sizeof(char) * strsize);
	file.read(reinterpret_cast <char*> (&(data->IntNum)), sizeof(int));
	
	file.close();
}
