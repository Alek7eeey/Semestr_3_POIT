#include "stdafx.h"
#include <stack>
#include <queue>
using namespace std;

bool PolishNotation(int i, LT::LexTable& lextable, IT::IdTable& idtable)
{
	stack<LT::Entry> stack;		// ���� ��� ��������
	queue<LT::Entry> queue;		// ������� ��� ���������
	int countLex = 0;// ���������� ��������������� ������
	int countParm = 0;// ���������� ���������� �������
	int posLex = i;// ���������� ����� ������� ����� ���������������
	bool findFunc = false;// ���� ��� �������
	bool findComma = false;// ���� ��� ������� (���-�� ���������� +2 �����)
	char* buf = new char[1];// ����� ��� countParm � ��������� �������������

	for (i; lextable.table[i].lexema != LEX_SEMICOLON; i++, countLex++)
	{
		switch (lextable.table[i].lexema)
		{
		case LEX_ID:// ���� �������������
		{
			if (idtable.table[lextable.table[i].idxTI - 1].idtype == IT::F)
				findFunc = true;
			queue.push(lextable.table[i]);
			continue;
		}
		case LEX_LITERAL:// ���� �������
		{
			queue.push(lextable.table[i]);// �������� � �������
			continue;
		}
		case LEX_LEFTTHESIS:// ���� (
		{
			lextable.table[i].priority = 0;
			stack.push(lextable.table[i]); // �������� �� � ����
			continue;
		}
		case LEX_RiGHTHESIS:// ���� )
		{
			lextable.table[i].priority = 0;
			if (findFunc)// ���� ��� ����� �������, �� ������� () ���������� �� @ � ���-�� ����������
			{
				if (findComma)
					countParm++;
				LT::Entry func; func.idxTI = -1; func.lexema = '@'; func.sn = lextable.table[i].sn;
				lextable.table[i] = func;
				queue.push(lextable.table[i]);// ��������� � ������� ������� ������ �������
				_itoa_s(countParm, buf, 2, 10);// �������������� ����� countParm � ������
				stack.top().lexema = buf[0]; stack.top().idxTI = -1; stack.top().sn = lextable.table[i].sn;// ��������� �������, ����������� ���������� ���������� �������
				queue.push(stack.top());// ��������� � ������� ��� �������
				findFunc = false;
			}
			else {
				while (stack.top().lexema != LEX_LEFTTHESIS  // ������� ��� (
					)// ���� �� �������� (
				{
					queue.push(stack.top());// ����������� �� ����� � �������
					stack.pop();

					if (stack.empty())
						return false;
				}
			}
			stack.pop();// ���������� ( ��� �������, ����������� ���������� ���������� �������
			continue;
		}
		case LEX_PLUS: case LEX_MINUS: case LEX_STAR:// ���� ���� ���������
		{
			if (lextable.table[i].lexema == LEX_PLUS || lextable.table[i].lexema == LEX_MINUS)
				lextable.table[i].priority = 2;
			if (lextable.table[i].lexema == LEX_STAR)
				lextable.table[i].priority = 3;

			if (lextable.table[i + 1].lexema == LEX_PLUS || lextable.table[i + 1].lexema == LEX_MINUS ||
				lextable.table[i + 1].lexema == LEX_STAR) {
				cout << "��� �������������� ��������� �� ����� ���� ���� �� ������!\n";
				return false;
			}
			while (!stack.empty() && lextable.table[i].priority <= stack.top().priority)// ���� ��������� �������� ���������
				// ������ ��� ����� ���������� ��������� � ������� �����
			{
				queue.push(stack.top());// ����������� �� ����� � �������� ������
				stack.pop();
			}
			stack.push(lextable.table[i]);
			continue;
		}
		case LEX_COMMA:// ���� �������
		{
			lextable.table[i].priority = 1;
			findComma = true;
			countParm++;
		}
		}
	}
	while (!stack.empty())// ���� ���� �� ������
	{
		if (stack.top().lexema == LEX_LEFTTHESIS || stack.top().lexema == LEX_RiGHTHESIS)
			return false;
		queue.push(stack.top());// ����������� ��� � �������
		stack.pop();
	}
	bool fr = true;

	LT::Entry temp;		temp.idxTI = -1;	temp.lexema = ' ';	temp.sn = lextable.table[posLex + countLex].sn;
	lextable.table[posLex + countLex] = temp;
	while (countLex != 0)// ������ �������� ��������� � ������� ������ �� ��������� � �����
	{
		if (!queue.empty()) {

			lextable.table[posLex++] = queue.front();
			queue.pop();
		}
		else
		{
			temp.idxTI = -1;	temp.lexema = ' ';	temp.sn = lextable.table[posLex].sn;
			if (fr) {
				temp.lexema = ';';
				fr = false;
			}
			lextable.table[posLex++] = temp;
		}

		countLex--;
	}

	for (int i = posLex - 1; i > -1; i--)// �������������� �������� ������� ��������� � �� � ���������� �� ��
	{
		if ((lextable.table[i].lexema == LEX_LITERAL || lextable.table[i].lexema == LEX_ID) && lextable.table[i].idxTI != -1) {
			idtable.table[lextable.table[i].idxTI].idxfirstLE = i;
		}

	}
	return true;
}

bool startPolishNotation(LT::LexTable& lextable, IT::IdTable& idtable)
{
	bool rc = false;
	for (int i = 0; i < lextable.size; i++)
	{
		if (lextable.table[i].lexema == '=')// ���� ����� �������� ������������
		{
			if (lextable.table[i + 1].lexema == '=') {
				i++;
				continue;
			}
			rc = PolishNotation(i + 1, lextable, idtable);// �������� ����� ��������� �� ��� �������
			if (!rc)
				return rc;
		}
	}
	return rc;
}

bool OutputPolish(LT::LexTable& lextable, IT::IdTable& idtable, In::IN in)
{
	int k = 1;
	cout << '\n' << k << ' ';
	bool flagENDL = false;
	for (int i = 0; i < lextable.size; i++)
	{

		if (lextable.table[i].lexema == '{' || lextable.table[i].lexema == 'e')
		{
			if (lextable.table[i].lexema == 'e' && !flagENDL)
			{
				if (k != 1)
				{
					cout << endl;
					k++;
				}

				cout << lextable.table[i].lexema;
			}
			if (k != 1 && lextable.table[i].lexema == 'e' && flagENDL)
			{
				cout << lextable.table[i].lexema;
				flagENDL = false;
			}
			flagENDL = false;
			if (lextable.table[i].lexema == '{')
			{
				cout << endl;
				k++;
				cout << k << ' ';
				cout << lextable.table[i].lexema;
			}
			if (lextable.table[i].lexema == 'e')
			{
				cout << lextable.table[i + 1].lexema;
				i++;
				cout << endl;
				k++;
				cout << k << ' ';
				flagENDL = true;
			}
			else if (k != in.lines)
			{
				cout << endl;
				k++;
				cout << k << ' ';
				flagENDL = true;
			}

		}

		else if (lextable.table[i].lexema == ';')
		{
			cout << lextable.table[i].lexema;
			if (k != in.lines)
			{
				cout << endl;
				k++;
				cout << k << ' ';
			}
			flagENDL = true;
		}

		else
		{
			cout << lextable.table[i].lexema;
		}
	}
	cout << endl << endl;
	return true;
}




