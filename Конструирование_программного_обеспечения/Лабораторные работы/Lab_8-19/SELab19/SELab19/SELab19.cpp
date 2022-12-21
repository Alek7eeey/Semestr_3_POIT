#include <iostream>
#include "stdafx.h"
using namespace fst;

int main()
{
	setlocale(LC_ALL, "Rus");

	fst::FST fst1(
		(char*)"aaabbbaba",
		4,						//���������� ���������    
		fst::NODE(3, fst::RELATION('a',0), fst::RELATION('b', 0), fst::RELATION('a',1)),
		fst::NODE(1, fst::RELATION('b', 2)),
		fst::NODE(1, fst::RELATION('a',3)),
		fst::NODE()
	);

	if (!execute(fst1))
	{
		cout << "������� " << fst1.string << " ����������" << endl;
	}
	else
	{
		cout << "������� " << fst1.string << " �� ����������" << endl;
	}

	FST fst2(
		(char*)"aaabbbaba", //(a+b)*aba
		4,         //���������� ���������    
		NODE(3, RELATION('a', 0), RELATION('b', 0), RELATION('a', 1)),
		NODE(1, RELATION('b', 2)),
		NODE(1, RELATION('a', 3)),
		NODE()
	);

	if (execute(fst2))
	{
		cout << "������� " << fst2.string << " ����������" << endl;
	}
	else
	{
		cout << "������� " << fst2.string << " �� ����������" << endl;
	}

	return 0;
}