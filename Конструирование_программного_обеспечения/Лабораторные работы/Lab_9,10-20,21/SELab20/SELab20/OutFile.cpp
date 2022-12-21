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

		Out << "\n\n������� ������:";
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

		Out << "\n\n������� ���������������:\n";
		for (int i = 0; i < idtable.size; i++)
		{
			if (idtable.table[i].iddatatype == 1)
			{
				if (idtable.table[i].idtype == 1)
				{
					Out << "��� ������: INT " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t��������: " << idtable.table[i].value.vint << "\t ��� ��������������: ����������" << '\n';
				}

				if (idtable.table[i].idtype == 2)
				{
					Out << "��� ������: INT " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t��������: " << idtable.table[i].value.vint << "\t ��� ��������������: �������" << '\n';
				}

				if (idtable.table[i].idtype == 3)
				{
					Out << "��� ������: INT " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t��������: " << idtable.table[i].value.vint << "\t ��� ��������������: ��������" << '\n';
				}

				if (idtable.table[i].idtype == 4)
				{
					Out << "��� ������: INT " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t��������: " << idtable.table[i].value.vint << "\t ��� ��������������: �������" << '\n';
				}
			}

			if (idtable.table[i].iddatatype == 2)
			{
				if (idtable.table[i].idtype == 1)
				{
					Out << "��� ������: STRING " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t�����: " << idtable.table[i].value.vstr->len << "\t ��� ��������������: ����������";

					if (idtable.table[i].value.vstr->len != 0)
					{
						Out << "\t ��������: ";
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
					Out << "��� ������: STRING " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t�����: " << idtable.table[i].value.vstr->len << "\t ��� ��������������: �������";
					if (idtable.table[i].value.vstr->len != 0)
					{
						Out << "\t ��������: ";
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
					Out << "��� ������: STRING " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t�����: " << idtable.table[i].value.vstr->len << "\t ��� ��������������: ��������";

					if (idtable.table[i].value.vstr->len != 0)
					{
						Out << "\t ��������: ";
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
					Out << "��� ������: STRING " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t�����: " << idtable.table[i].value.vstr->len << "\t ��� ��������������: �������" << "\t ��������: ";
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