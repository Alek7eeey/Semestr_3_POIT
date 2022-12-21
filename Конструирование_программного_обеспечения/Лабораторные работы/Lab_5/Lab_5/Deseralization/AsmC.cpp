#include "Stdafx.h"

using namespace std;

void AsmConvenrter::call()
{
	file = ofstream("D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Лабораторные работы\\Lab_5(n)\\Lab_5\\Assembler\\Test3.asm");

	short strsize = wcslen(data.WcharVal) + 1;
	size_t convertedChars = 0;

	const size_t newsize = strsize * 2;
	char* nstring = new char[newsize];

	wcstombs_s(&convertedChars, nstring, newsize, data.WcharVal, _TRUNCATE);

	file.clear();

	file ASMHEADER;

	file << "FILESTR	 DB \"" << nstring << "\", 0" << endl << endl;

	file << "FILEINT	 DD " << '0' + data.IntNum << endl << endl;
	file << "INTSTR		DB \"num: \", 0" << endl;

	file ASMFOOTER;

	file.close();
}
