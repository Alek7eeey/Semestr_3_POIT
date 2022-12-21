#include "stdafx.h"
#include "OutFile.h"
#include <iostream>

namespace OutFILE
{
	void WriteOutFile(int argc, wchar_t* argv[], LT::LexTable& lextable,IT::IdTable& idtable)
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		std::ofstream Out(parm.out);
		Out << in.text;

		Out << "\n\nТаблица лексем:";
		int k = 1;
		Out << '\n' << k << ' ';
		for (int i = 0; i < lextable.size; i++)
		{

			if (lextable.table[i].lexema == '{')
			{
				Out << '\n';
				k++;
				Out << k << ' ';
				Out << lextable.table[i].lexema;
				if (k != in.lines)
				{
					Out << '\n';
					k++;
					Out << k << ' ';
				}

			}

			else if (lextable.table[i].lexema == ';')
			{
				Out << lextable.table[i].lexema;
				if (k != in.lines)
				{
					Out << '\n';
					k++;
					Out << k << ' ';
				}
			}

			else
			{
				Out << lextable.table[i].lexema;
			}
		}

		Out << "\n\nТаблица идентификаторов:\n";
		for (int i = 0; i < idtable.size; i++)
		{
			if (idtable.table[i].iddatatype == 1)
			{
				if (idtable.table[i].idtype == 1)
				{
					Out << "Тип данных: INT " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tзначение: " << idtable.table[i].value.vint << "\t тип идентификатора: переменная" << '\n';
				}

				if (idtable.table[i].idtype == 2)
				{
					Out << "Тип данных: INT " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tзначение: " << idtable.table[i].value.vint << "\t тип идентификатора: функция" << '\n';
				}

				if (idtable.table[i].idtype == 3)
				{
					Out << "Тип данных: INT " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tзначение: " << idtable.table[i].value.vint << "\t тип идентификатора: параметр" << '\n';
				}

				if (idtable.table[i].idtype == 4)
				{
					Out << "Тип данных: INT " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tзначение: " << idtable.table[i].value.vint << "\t тип идентификатора: литерал" << '\n';
				}
			}

			if (idtable.table[i].iddatatype == 2)
			{
				if (idtable.table[i].idtype == 1)
				{
					Out << "Тип данных: STRING " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tдлина: " << idtable.table[i].value.vstr->len << "\t тип идентификатора: переменная";

					if (idtable.table[i].value.vstr->len != 0)
					{
						Out << "\t значение: ";
						for (int j = 0; j < idtable.table[i].value.vstr->len; j++)
						{
							Out << idtable.table[i].value.vstr->str[j];
						}
						Out << '\n';
					}
					else Out << '\n';
				}

				if (idtable.table[i].idtype == 2)
				{
					Out << "Тип данных: STRING " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tдлина: " << idtable.table[i].value.vstr->len << "\t тип идентификатора: функция";
					if (idtable.table[i].value.vstr->len != 0)
					{
						Out << "\t значение: ";
						for (int j = 0; j < idtable.table[i].value.vstr->len; j++)
						{
							Out << idtable.table[i].value.vstr->str[j];
						}
						Out << '\n';
					}
					else Out << '\n';
				}

				if (idtable.table[i].idtype == 3)
				{
					Out << "Тип данных: STRING " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tдлина: " << idtable.table[i].value.vstr->len << "\t тип идентификатора: параметр";

					if (idtable.table[i].value.vstr->len != 0)
					{
						Out << "\t значение: ";
						for (int j = 0; j < idtable.table[i].value.vstr->len; j++)
						{
							Out << idtable.table[i].value.vstr->str[j];
						}
						Out << '\n';
					}
					else Out << '\n';
				}

				if (idtable.table[i].idtype == 4)
				{
					Out << "Тип данных: STRING " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tдлина: " << idtable.table[i].value.vstr->len << "\t тип идентификатора: литерал" << "\t значение: ";
					for (int j = 0; j < idtable.table[i].value.vstr->len; j++)
					{
						Out << idtable.table[i].value.vstr->str[j];
					}
					Out << '\n';
				}
			}
		}
		Out << '\n';
		Out.close();
	}
}