#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

namespace fst
{
	struct RELATION //ребро:cbvdjk -> вершина графа переходов КА
	{
		char symbol;
		short nnode;
		RELATION
		(
			char c = 0x00, //символ перехода
			short ns = NULL //новое состояние
		);
	};

	struct NODE //вершина графа перехода
	{
		short n_relation; //кол-во инциндентных ребер
		RELATION* relations; //инцидентные ребра
		NODE();
		NODE(
			short n,	//кол-во инциндентных ребер
			RELATION rel, ...		//список рёбер
		);
	};

	struct FST		//недетерминированный конечный автомат
	{
		char* string; //цепочка (строка, завершается 0х00)
		short position; //текущая позиция в цепочке
		short nstates;	//кол-во состояний автомата
		NODE* nodes; //граф переходов: [0] - начальное состояние, [nstate-1] - конечное
		short* rstates; //возможные состояния автомата на данной позиции
		FST(
			char* s, //цепочка(строка, завершается 0х00)
			short ns, //кол-во состояний автомата
			NODE n, ... //список состояний (граф переходов)
		);
	};

	bool execute( //выполнить распознование цепочки
		FST& fst //недетерминированный конечный автомат
	);
}