#include "stdafx.h"
#include <string>

using namespace std;

void AsmConvenrter::Invoke()
{
	file = ofstream("D:\\studing\\3 семестр\\Конструирование_программного_обеспечения\\Лабораторные работы\\Lab_5\\Serealization\\AssemblerProgramm\\test3.asm");
	//string s = to_string(data.Int);
	file.clear();

	file ASMHEADER;

		 file<< "FILESTR	 DB \"" << data.String << "\", 0" << endl << endl;
		 //file << "FILESTR2	 DB \"" << s << "\", 0" << endl << endl;

		 file<< "FILEINT	 DD " << '0' + data.Int << endl << endl;
		 file << "INTSTR		DB \"num: \", 0"<<endl;

	file ASMFOOTER;

	file.close();
}
