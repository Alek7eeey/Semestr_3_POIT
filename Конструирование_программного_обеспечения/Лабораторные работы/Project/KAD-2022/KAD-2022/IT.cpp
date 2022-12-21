#include "stdafx.h"
#include "IT.h"
#include <iostream>

namespace IT
{
	IdTable Create(int size)
	{
		if (size >= TI_MAXSIZE)
		{
			throw ERROR_THROW(14);
		}

		IdTable idtable;
		idtable.maxsize = size;
		idtable.size = 0;
		idtable.table = new Entry[size];

		return idtable;
	}

	void Add(IdTable& idtable, Entry entry)
	{
		if (idtable.size >= idtable.maxsize)
		{
			throw ERROR_THROW(14);
		}

		idtable.table[idtable.size] = entry;
		idtable.size++;
	}

	Entry GetEntry(IdTable& idtable, int n)
	{
		if (n < 0 || n >= idtable.size)
		{
			throw ERROR_THROW(15);
		}
		return idtable.table[n];
	}

	int IsId(IdTable& idtable, std::string id)
	{
		for (short i = 0; i < idtable.size; i++)
		{
			if (idtable.table[i].id == id)
			{
				return i;
			}
		}

		return TI_NULLIDX;
	}

	void Delete(IdTable& idtable)
	{
		delete[]idtable.table;
		idtable.size = 0;
		idtable.maxsize = 0;
	}

	int GetIndexByLTIndex(IdTable& idtable, int index)
	{
		int ind = -1;

		for (int i = 0; i < idtable.size; i++)
		{
			if (idtable.table[i].idxfirstLE == index)
			{
				ind = i;
				break;
			}
		}

		return ind;
	}
}