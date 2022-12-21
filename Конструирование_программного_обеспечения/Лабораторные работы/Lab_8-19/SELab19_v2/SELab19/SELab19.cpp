// SELab19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "stdafx.h"
using namespace fst;

void main()
{
	setlocale(LC_ALL, "ru");

	FST fst1(
		(char*)"abaaba", //(a+b)*aba
		4,         //количество состояний    
		NODE(3, RELATION('a', 0), RELATION('b', 0), RELATION('a', 1) ), 
		NODE(1, RELATION('b', 2)),
		NODE(1, RELATION('a', 3)),
		NODE()
	);

	if (execute(fst1))
	{
		cout << "Цепочка " << fst1.string << " распознана" << endl;
	}
	else
	{
		cout << "Цепочка " << fst1.string << " не распознана" << endl;
	}
	FST fst2(
		(char*)"aabbaa", 
		4,            
		NODE(3, RELATION('a', 0), RELATION('b', 0), RELATION('a', 1)), 
		NODE(1, RELATION('b', 2)),
		NODE(1, RELATION('a', 3)),
		NODE()
	);

	if (execute(fst2))
	{
		cout << "Цепочка " << fst2.string << " распознана" << endl;
	}
	else
	{
		cout << "Цепочка " << fst2.string << " не распознана" << endl;
	}

	FST fst3( //start(@)+(e+w+0)*stop  

		(char*)"Start@@@@@@eeoooowStop",
		12,
		NODE(1, RELATION('S', 1)),
		NODE(1, RELATION('t', 2)),
		NODE(1, RELATION('a', 3)),
		NODE(1, RELATION('r', 4)),
		NODE(1, RELATION('t', 5)),
		NODE(3, RELATION('@', 5), RELATION('@', 6), RELATION('@', 7)),
		NODE(6, RELATION('e', 6), RELATION('w', 6), RELATION('o', 6), RELATION('e', 7), RELATION('w', 7), RELATION('o', 7)),
		NODE(1, RELATION('S', 8)),
		NODE(1, RELATION('t', 9)),
		NODE(1, RELATION('o', 10)),
		NODE(1, RELATION('p', 11)),
		NODE()
	);

	if (execute(fst3))
	{
		cout << "Цепочка " << fst3.string << " распознана" << endl;
	}
	else
	{
		cout << "Цепочка " << fst3.string << " не распознана" << endl;
	}

	FST fst4( //start(@)+(e+w+0)*stop  
		
		(char*)"Start@eewStop",
		12,
		NODE(1, RELATION('S', 1)),
		NODE(1, RELATION('t', 2)),
		NODE(1, RELATION('a', 3)),
		NODE(1, RELATION('r', 4)),
		NODE(1, RELATION('t', 5)),
		NODE(3, RELATION('@', 5), RELATION('@', 6), RELATION('@', 7)),
		NODE(6, RELATION('e', 6), RELATION('w', 6), RELATION('o', 6), RELATION('e', 7), RELATION('w', 7), RELATION('o', 7)),
		NODE(1, RELATION('S', 8)),
		NODE(1, RELATION('t', 9)),
		NODE(1, RELATION('o', 10)),
		NODE(1, RELATION('p', 11)),
		NODE()	
	);

	if (execute(fst4))
	{
		cout << "Цепочка " << fst4.string << " распознана" << endl;
	}
	else
	{
		cout << "Цепочка " << fst4.string << " не распознана" << endl;
	}
	FST fst5( //start(@)+(e+w+0)*stop  

		(char*)"Start@@@@wStop",
		12,
		NODE(1, RELATION('S', 1)),
		NODE(1, RELATION('t', 2)),
		NODE(1, RELATION('a', 3)),
		NODE(1, RELATION('r', 4)),
		NODE(1, RELATION('t', 5)),
		NODE(3, RELATION('@', 5), RELATION('@', 6), RELATION('@', 7)),
		NODE(6, RELATION('e', 6), RELATION('w', 6), RELATION('o', 6), RELATION('e', 7), RELATION('w', 7), RELATION('o', 7)),
		NODE(1, RELATION('S', 8)),
		NODE(1, RELATION('t', 9)),
		NODE(1, RELATION('o', 10)),
		NODE(1, RELATION('p', 11)),
		NODE()
	);

	if (execute(fst5))
	{
		cout << "Цепочка " << fst5.string << " распознана" << endl;
	}
	else
	{
		cout << "Цепочка " << fst5.string << " не распознана" << endl;
	}
	FST fst6( //start(@)+(e+w+0)*stop  

		(char*)"Start@Stop",
		12,
		NODE(1, RELATION('S', 1)),
		NODE(1, RELATION('t', 2)),
		NODE(1, RELATION('a', 3)),
		NODE(1, RELATION('r', 4)),
		NODE(1, RELATION('t', 5)),
		NODE(3, RELATION('@', 5), RELATION('@', 6), RELATION('@', 7)),
		NODE(6, RELATION('e', 6), RELATION('w', 6), RELATION('o', 6), RELATION('e', 7), RELATION('w', 7), RELATION('o', 7)),
		NODE(1, RELATION('S', 8)),
		NODE(1, RELATION('t', 9)),
		NODE(1, RELATION('o', 10)),
		NODE(1, RELATION('p', 11)),
		NODE()
	);

	if (execute(fst6))
	{
		cout << "Цепочка " << fst6.string << " распознана" << endl;
	}
	else
	{
		cout << "Цепочка " << fst6.string << " не распознана" << endl;
	}
	FST fst7( //start(@)+(e+w+0)*stop  

		(char*)"Start@@eoStop",
		12,
		NODE(1, RELATION('S', 1)),
		NODE(1, RELATION('t', 2)),
		NODE(1, RELATION('a', 3)),
		NODE(1, RELATION('r', 4)),
		NODE(1, RELATION('t', 5)),
		NODE(3, RELATION('@', 5), RELATION('@', 6), RELATION('@', 7)),
		NODE(6, RELATION('e', 6), RELATION('w', 6), RELATION('o', 6), RELATION('e', 7), RELATION('w', 7), RELATION('o', 7)),
		NODE(1, RELATION('S', 8)),
		NODE(1, RELATION('t', 9)),
		NODE(1, RELATION('o', 10)),
		NODE(1, RELATION('p', 11)),
		NODE()
	);

	if (execute(fst7))
	{
		cout << "Цепочка " << fst7.string << " распознана" << endl;
	}
	else
	{
		cout << "Цепочка " << fst7.string << " не распознана" << endl;
	}
	FST fst8( //start(@)+(e+w+0)*stop  

		(char*)"StartM@@eoStop",//заверш разбор не перебр все символы 
		12,
		NODE(1, RELATION('S', 1)),
		NODE(1, RELATION('t', 2)),
		NODE(1, RELATION('a', 3)),
		NODE(1, RELATION('r', 4)),
		NODE(1, RELATION('t', 5)),
		NODE(3, RELATION('@', 5), RELATION('@', 6), RELATION('@', 7)),
		NODE(6, RELATION('e', 6), RELATION('w', 6), RELATION('o', 6), RELATION('e', 7), RELATION('w', 7), RELATION('o', 7)),
		NODE(1, RELATION('S', 8)),
		NODE(1, RELATION('t', 9)),
		NODE(1, RELATION('o', 10)),
		NODE(1, RELATION('p', 11)),
		NODE()
	);

	if (execute(fst8))
	{
		cout << "Цепочка " << fst8.string << " распознана" << endl;
	}
	else
	{
		cout << "Цепочка " << fst8.string << " не распознана" << endl;
	}
	FST fst9( //start(@)+(e+w+0)*stop  

		(char*)"StartStart@@eoStop",//разбор проходит все символы входной  цепочки, но при этом, цепочка не распознается
		12,
		NODE(1, RELATION('S', 1)),
		NODE(1, RELATION('t', 2)),
		NODE(1, RELATION('a', 3)),
		NODE(1, RELATION('r', 4)),
		NODE(1, RELATION('t', 5)),
		NODE(3, RELATION('@', 5), RELATION('@', 6), RELATION('@', 7)),
		NODE(6, RELATION('e', 6), RELATION('w', 6), RELATION('o', 6), RELATION('e', 7), RELATION('w', 7), RELATION('o', 7)),
		NODE(1, RELATION('S', 8)),
		NODE(1, RELATION('t', 9)),
		NODE(1, RELATION('o', 10)),
		NODE(1, RELATION('p', 11)),
		NODE()
	);

	if (execute(fst9))
	{
		cout << "Цепочка " << fst9.string << " распознана" << endl;
	}
	else
	{
		cout << "Цепочка " << fst9.string << " не распознана" << endl;
	}
}