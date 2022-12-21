#include "stdafx.h"
#include "LT.h"
#include <iostream>

namespace LT
{
	LexTable Create(int size)
	{
		if (size > LT_MAXSIZE)
		{
			throw ERROR_THROW(12);
		}

		LexTable lextable;
		lextable.maxsize = size;
		lextable.size = 0;
		lextable.table = new Entry[size];

		return lextable;
	}

	void Add(LexTable& lextable, Entry entry)
	{
		if (lextable.size >= lextable.maxsize)
		{
			throw ERROR_THROW(12);
		}

		lextable.table[lextable.size] = entry;
		lextable.size++;
	}

	Entry GetEntry(LexTable& lextable, int n)
	{
		if (n >= lextable.size || n < 0)
		{
			throw ERROR_THROW(13);
		}

		return lextable.table[n];
	}

	void Delete(LexTable& lextable)
	{
		delete[]lextable.table;
		lextable.size = 0;
		lextable.maxsize = 0;
	}
}