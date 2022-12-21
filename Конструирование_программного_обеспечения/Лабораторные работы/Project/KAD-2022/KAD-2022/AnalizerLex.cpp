#include "stdafx.h"
#include "AnalizerLex.h"
#include <fstream>
#include <iostream>
#include <stack>
#include <string>

#define ClearStack 	while (!stc.empty())\
		{\
		stc.pop();\
		}

using namespace std;

namespace AnalizerLex
{
	stack <std::string> stc;
	bool flagINT = false;
	bool flagSTR = false;
	bool flagEQUAL = false;
	bool flagARG = false;
	bool flagFUNC = false;
	bool flagBodyFUNC = false;
	bool flagENDL = false;
	bool flagMAIN = false;
	bool flagStaticFUNC = false;
	bool flagPrint = false;
	char arrNumber[11] = { '1','2','3','4','5','6','7','8','9','0' };
	static std::string nameFunction;
	static std::string nameStaticFunction;
	static int countLiteral = 0;
	static std::string print = "";
	static int countSingleQuote = 0;

	void LexAnalize(In::IN in,
		LT::LexTable& lextable,
		IT::IdTable& idtable)
	{
		int numbLine = 1;
		string word = "";
		int timeCount = in.size;

		for (int i = 0; i < timeCount; i++)
		{
			if (in.text[i] == ' ')
			{
				FillingTables(word, lextable, idtable, stc, numbLine);
				word = "";
				i++;
			}

			if (in.text[i] == '\n')
			{
				FillingTables(word, lextable, idtable, stc, numbLine);
				numbLine += 1;
				word = "";
				i++;
			}
			if (word == "\n" || word == "\t")
			{
				word = "";
			}
			word += in.text[i];

			if (in.text[i + 1] == '\0')
			{
				FillingTables(word, lextable, idtable, stc, numbLine);
				word = "";
				i++;
			}
		}
		int k = 1;
		cout << '\n' << k << ' ';
		flagENDL = false;
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
					cout << lextable.table[i+1].lexema;
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

		for (int i = 0; i < idtable.size; i++)
		{
			if (idtable.table[i].iddatatype == 1)
			{
				if (idtable.table[i].idtype == 1)
				{
					cout << "Тип данных: NUMBER " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tзначение: " << idtable.table[i].value.vint << "\t тип идентификатора: переменная" << endl;
				}

				if (idtable.table[i].idtype == 2)
				{
					cout << "Тип данных: NUMBER " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tзначение: " << idtable.table[i].value.vint << "\t тип идентификатора: функция" << endl;
				}

				if (idtable.table[i].idtype == 3)
				{
					cout << "Тип данных: NUMBER " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tзначение: " << idtable.table[i].value.vint << "\t тип идентификатора: параметр" << endl;
				}

				if (idtable.table[i].idtype == 4)
				{
					cout << "Тип данных: NUMBER " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tзначение: " << idtable.table[i].value.vint << "\t тип идентификатора: литерал" << endl;
				}
			}

			if (idtable.table[i].iddatatype == 2)
			{
				if (idtable.table[i].idtype == 1)
				{
					cout << "Тип данных: LINE " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tдлина: " << idtable.table[i].value.vstr->len << "\t тип идентификатора: переменная";

					if (idtable.table[i].value.vstr->len != 0)
					{
						cout << "\t значение: ";
						for (int j = 0; j < idtable.table[i].value.vstr->len; j++)
						{
							cout << idtable.table[i].value.vstr->str[j];
						}
						cout << endl;
					}
					else cout << endl;
				}

				if (idtable.table[i].idtype == 2)
				{
					cout << "Тип данных: LINE " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tдлина: " << idtable.table[i].value.vstr->len << "\t тип идентификатора: функция";

					if (idtable.table[i].value.vstr->len != 0)
					{
						cout << "\t значение: ";
						for (int j = 0; j < idtable.table[i].value.vstr->len; j++)
						{
							cout << idtable.table[i].value.vstr->str[j];
						}
						cout << endl;
					}
					else cout << endl;
				}

				if (idtable.table[i].idtype == 3)
				{
					cout << "Тип данных: LINE " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tдлина: " << idtable.table[i].value.vstr->len << "\t тип идентификатора: параметр";
					if (idtable.table[i].value.vstr->len != 0)
					{
						cout << "\t значение: ";
						for (int j = 0; j < idtable.table[i].value.vstr->len; j++)
						{
							cout << idtable.table[i].value.vstr->str[j];
						}
						cout << endl;
					}
					else cout << endl;
				}

				if (idtable.table[i].idtype == 4)
				{
					cout << "Тип данных: LINE " << "\t идентификатор: " << idtable.table[i].id << "\t строка: " << idtable.table[i].idxfirstLE
						<< "\tдлина: " << idtable.table[i].value.vstr->len << "\t тип идентификатора: литерал" << "\t значение: ";
					for (int j = 0; j < idtable.table[i].value.vstr->len; j++)
					{
						cout << idtable.table[i].value.vstr->str[j];
					}
					cout << endl;
				}
			}
		}
		cout << endl;
	}

	bool FillingTables(std::string text,
		LT::LexTable& lextable,
		IT::IdTable& idtable,
		stack <string>& stc,
		int nLine)
	{
		LT::Entry lexTbl;
		IT::Entry idTbl;

		if (text == "number")
		{
			lexTbl.lexema = LEX_INTEGER;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			stc.push(text);
			flagINT = true;
			return true;
		}

		else if (text == "line")
		{
			lexTbl.lexema = LEX_STRING;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			stc.push(text);
			flagSTR = true;
			return true;
		}

		else if (text == "function")
		{
			lexTbl.lexema = LEX_FUNCTION;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			stc.push(text);
			flagFUNC = true;
			return true;
		}

		else if (text == "new")
		{
			lexTbl.lexema = LEX_NEW;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			return true;
		}

		else if (text == "return")
		{
			lexTbl.lexema = LEX_RETURN;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			return true;
		}

		else if (text == "print")
		{
			lexTbl.lexema = LEX_PRINT;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			flagPrint = true;
			return true;
		}

		else if (text == "main")
		{
			lexTbl.lexema = LEX_MAIN;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			flagMAIN = true;
			nameFunction = "main";
			return true;
		}

		else if (text == ";")
		{
			lexTbl.lexema = LEX_SEMICOLON;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			flagENDL = true;
			flagEQUAL = false;
			if (((flagFUNC && flagBodyFUNC) || flagMAIN) && (flagINT || flagSTR) && flagENDL) //тело функции типа int a;
			{
				idTbl.id = nameFunction + stc.top();
				ClearStack

				if (flagINT)
				{
					idTbl.iddatatype = IT::INT;
					flagINT = false;
				}

				if (flagSTR)
				{
					idTbl.iddatatype = IT::STR;
					flagSTR = false;
				}

				idTbl.idtype = IT::V;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vint = 0;
				IT::Add(idtable, idTbl);
				flagENDL = false;

				return true;
			}

			if (flagINT || flagSTR) //только флаг инт или стринг
			{
				idTbl.id = stc.top();
				ClearStack

				if (flagINT)
				{
					idTbl.iddatatype = IT::INT;
					flagINT = false;
				}

				if (flagSTR)
				{
					idTbl.iddatatype = IT::STR;
					flagSTR = false;
				}

				idTbl.idtype = IT::V;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vint = 0;
				IT::Add(idtable, idTbl);
			}
			return true;
		}

		else if (text == ",")
		{
			lexTbl.lexema = LEX_COMMA;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			return true;
		}

		else if (text == "{")
		{
			lexTbl.lexema = LEX_LEFTBRACE;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			if (flagFUNC || flagMAIN)
			{
				flagBodyFUNC = true;
			}
			return true;
		}

		else if (text == "}")
		{
			lexTbl.lexema = LEX_BRACELET;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			if (flagFUNC && flagBodyFUNC)
			{
				flagFUNC = false;
				flagBodyFUNC = false;
				nameFunction = "";
			}

			if (flagMAIN)
			{
				flagMAIN = false;
				nameFunction = "";
			}
			return true;
		}

		else if (text == "(")
		{
			lexTbl.lexema = LEX_LEFTTHESIS;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			if (flagFUNC || flagStaticFUNC)
			{
				flagARG = true;
			}
			return true;
		}

		else if (text == ")")
		{
			lexTbl.lexema = LEX_RiGHTHESIS;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);

			if (flagFUNC)
			{
				flagARG = false;
			}

			if (flagStaticFUNC)
			{
				flagStaticFUNC = false;
				flagARG = false;
				nameStaticFunction = "";
			}

			return true;
		}

		else if (text == "+")
		{
			lexTbl.lexema = LEX_PLUS;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			lexTbl.znak.znak = '+';
			LT::Add(lextable, lexTbl);
			return true;
		}

		else if (text == "-")
		{
			lexTbl.lexema = LEX_MINUS;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			lexTbl.znak.znak = '-';
			LT::Add(lextable, lexTbl);
			return true;
		}

		else if (text == "*")
		{
			lexTbl.lexema = LEX_STAR;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			lexTbl.znak.znak = '*';
			LT::Add(lextable, lexTbl);
			return true;
		}

		else if (text == "/")
		{
			lexTbl.lexema = LEX_DIRSLASH;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			lexTbl.znak.znak = '/';
			LT::Add(lextable, lexTbl);
			return true;
		}

		else if (text == ">>")
		{
			lexTbl.lexema = LEX_RAVNO;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			flagEQUAL = true;

			return true;
		}

		else if (text == "procedure")
		{
		lexTbl.lexema = LEX_PROCEDURE;
		lexTbl.sn = nLine;
		lexTbl.idxTI = LT_TI_NULLIDX;
		LT::Add(lextable, lexTbl);
		flagPrint = true;
		return true;
		}

		else if (text == "%")
		{
		lexTbl.lexema = LEX_REMAINDER;
		lexTbl.sn = nLine;
		lexTbl.idxTI = LT_TI_NULLIDX ;
		LT::Add(lextable, lexTbl);
		return true;
		}

		else if (text == "newline")
		{
			lexTbl.lexema = LEX_NEWLINE;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			return true;
		}

		else if(text == "while")
		{
			lexTbl.lexema = LEX_CYCLE;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			return true;
		}

		if (text == "copy")
		{
			lexTbl.lexema = LEX_ID;
			lexTbl.sn = nLine;

			if (IT::IsId(idtable, "copy") != TI_NULLIDX)
			{
				lexTbl.idxTI = IsId(idtable, "copy");
				LT::Add(lextable, lexTbl);
				nameStaticFunction = "copy";
			}
			else
			{
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);
				idTbl.id = "copy";
				nameStaticFunction = "copy";
				idTbl.iddatatype = IT::STR;
				idTbl.idtype = IT::F;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vstr->len = 0;
				idTbl.value.vstr->str[0] = '\0';
				IT::Add(idtable, idTbl);
			}
			ClearStack
			flagSTR = false;
			flagStaticFUNC = true;
			flagEQUAL = false;
			return true;
		}

		if (text == "lenght")
		{
			lexTbl.lexema = LEX_ID;
			lexTbl.sn = nLine;

			if (IT::IsId(idtable, "lenght") != TI_NULLIDX)
			{
				lexTbl.idxTI = IsId(idtable, "lenght");
				LT::Add(lextable, lexTbl);
				nameStaticFunction = "lenght";
			}
			else
			{
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);
				idTbl.id = "lenght";
				nameStaticFunction = "lenght";
				idTbl.iddatatype = IT::INT;
				idTbl.idtype = IT::F;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vint = 0;
				IT::Add(idtable, idTbl);
			}
			ClearStack
			flagINT = false;
			flagStaticFUNC = true;
			flagEQUAL = false;
			return true;
		}

		if (flagStaticFUNC && flagARG && (flagINT || flagSTR)) //copy(int a)
		{
			if (flagINT)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);
				stc.push(text);

				if (IT::IsId(idtable, nameStaticFunction + stc.top()) == TI_NULLIDX)
				{
					idTbl.id = nameStaticFunction + stc.top();
					idTbl.iddatatype = IT::INT;
					idTbl.idtype = IT::P;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vint = 0;
					IT::Add(idtable, idTbl);
				}
				ClearStack

				flagINT = false;
			}

			if (flagSTR)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				if (IT::IsId(idtable, nameStaticFunction + stc.top()) != TI_NULLIDX)
				{
					lexTbl.idxTI = IsId(idtable, nameStaticFunction + stc.top());
				}
				else
				{
					lexTbl.idxTI = LT_TI_NULLIDX;
					LT::Add(lextable, lexTbl);

					stc.push(text);
					idTbl.id = nameStaticFunction + stc.top();
					idTbl.iddatatype = IT::STR;
					idTbl.idtype = IT::P;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vstr->len = 0;
					idTbl.value.vstr->str[0] = '\0';
					IT::Add(idtable, idTbl);
				}
				ClearStack
				flagSTR = false;
			}

			return true;
		}

		if (((flagFUNC && flagBodyFUNC) || flagMAIN) && flagEQUAL && (flagINT || flagSTR)) //тело функции типа int a = 10;
		{
			if (flagINT && IsNumberOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);
			
				if (IT::IsId(idtable, nameFunction + stc.top()) == TI_NULLIDX)
				{
					idTbl.id = nameFunction + stc.top();

					idTbl.iddatatype = IT::INT;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;
					if (stoi(text) != 0)
					{
						idTbl.value.vint = stoi(text);
					}
					else
					{
						idTbl.value.vint = 0;
					}
					IT::Add(idtable, idTbl);
				}
				ClearStack
				flagINT = false;
			}

			if (flagSTR && IsStrokeOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);

				if (IT::IsId(idtable, nameFunction + stc.top()) == TI_NULLIDX)
				{
					idTbl.id = nameFunction + stc.top();
					ClearStack
					idTbl.iddatatype = IT::STR;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;

					if (IsStrokeOrNot(text))
					{
						idTbl.value.vstr->len = text.size();
						idTbl.value.vstr->str[text.size()] = (char)text.c_str();
					}
					else
					{
						idTbl.value.vstr->len = 0;
						idTbl.value.vstr->str[0] = '\0';
					}

					IT::Add(idtable, idTbl);
				}
				flagSTR = false;
			}

			return true;
		}

		if (!flagEQUAL && !flagINT && !flagSTR && IsNumberOrNot(text)) //просто литерал - цифра
		{
			lexTbl.lexema = LEX_LITERAL;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);

			//------------------
			idTbl.id = "L" + std::to_string(countLiteral);
			idTbl.iddatatype = IT::INT;
			idTbl.idtype = IT::L;
			idTbl.idxfirstLE = nLine;
			idTbl.value.vint = stoi(text);
			IT::Add(idtable, idTbl);
			countLiteral++;
			return true;
		}

		if (!flagEQUAL && flagARG && IsNumberOrNot(text)) //параметры Литерал число
		{
			lexTbl.lexema = LEX_LITERAL;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);

			idTbl.id = "L" + std::to_string(countLiteral);
			idTbl.iddatatype = IT::INT;
			idTbl.idtype = IT::L;
			idTbl.idxfirstLE = nLine;
			idTbl.value.vint = stoi(text);
			IT::Add(idtable, idTbl);
			countLiteral++;
			return true;
		}

		if (!flagEQUAL && flagARG && !flagINT &&!flagSTR && !flagBodyFUNC) //параметры идентификатор
		{
			lexTbl.lexema = LEX_ID;
			lexTbl.sn = nLine;


			if (IT::IsId(idtable, text) != TI_NULLIDX)
			{
				lexTbl.idxTI = IsId(idtable, text );
				LT::Add(lextable, lexTbl);
			}
			else
			{
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);
				stc.push(text);
				idTbl.id = text;
				idTbl.iddatatype = IT::INT;
				idTbl.idtype = IT::P;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vint = 0;
				IT::Add(idtable, idTbl);
			}
			ClearStack
			return true;
		}

		if (flagEQUAL && ((flagFUNC && flagBodyFUNC) || flagMAIN)) //тело функции типа a = 10;
			
			if (IsNumberOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);
			
				if (IT::IsId(idtable, nameFunction + stc.top()) != TI_NULLIDX)
				{
					//------------------
					idTbl.id = "L" + std::to_string(countLiteral);
					idTbl.iddatatype = IT::INT;
					idTbl.idtype = IT::L;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vint = stoi(text);
					IT::Add(idtable, idTbl);
					countLiteral++;
				}
				else
				{
					idTbl.id = nameFunction + stc.top();
					idTbl.iddatatype = IT::INT;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vint = stoi(text);
					IT::Add(idtable, idTbl);
				}
				ClearStack
					return true;
			}

			else if (IsStrokeOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);

				if (IT::IsId(idtable, nameFunction + stc.top()) != TI_NULLIDX)
				{

					//---------------
					idTbl.id = "L" + std::to_string(countLiteral);
					idTbl.iddatatype = IT::STR;
					idTbl.idtype = IT::L;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vstr->len = text.size();
					text.copy(idTbl.value.vstr->str, text.size());
					IT::Add(idtable, idTbl);
					countLiteral++;
				}
				else
				{
					idTbl.id = nameFunction + stc.top();
					idTbl.iddatatype = IT::STR;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vstr->len = text.size();
					text.copy(idTbl.value.vstr->str, text.size() + 1);
					IT::Add(idtable, idTbl);
				}

				ClearStack
					return true;
			}

			else
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;

				if (IT::IsId(idtable, nameFunction + text) != TI_NULLIDX)
				{
					lexTbl.idxTI = IsId(idtable, nameFunction + text);
					LT::Add(lextable, lexTbl);
				}
				if (IT::IsId(idtable, text) != TI_NULLIDX)
				{
					lexTbl.idxTI = IsId(idtable, text);
					LT::Add(lextable, lexTbl);
				}

				if(IT::IsId(idtable, nameFunction + text) == TI_NULLIDX && IT::IsId(idtable, text) == TI_NULLIDX) ///////////////////////////////
				{
					lexTbl.idxTI = LT_TI_NULLIDX;
					LT::Add(lextable, lexTbl);
					idTbl.id = nameFunction + text;
					idTbl.iddatatype = IT::STR;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vstr->len = text.size();
					text.copy(idTbl.value.vstr->str, text.size() + 1);
					IT::Add(idtable, idTbl);
				}
				ClearStack
				flagEQUAL = false;
				return true;
			}

		if (((flagFUNC||flagStaticFUNC) && flagARG) && (flagINT || flagSTR)) //параметры функции
		{
			if (flagINT)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;

				if (IT::IsId(idtable, nameFunction + stc.top()) != TI_NULLIDX)
				{
					lexTbl.idxTI = IsId(idtable, nameFunction + stc.top());
					LT::Add(lextable, lexTbl);
				}
				else
				{
					lexTbl.idxTI = LT_TI_NULLIDX;
					LT::Add(lextable, lexTbl);
					stc.push(text);
					idTbl.id = nameFunction + stc.top();
					idTbl.iddatatype = IT::INT;
					idTbl.idtype = IT::P;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vint = 0;
					IT::Add(idtable, idTbl);
				}
				ClearStack
				flagINT = false;
			}

			if (flagSTR)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				if (IT::IsId(idtable, nameFunction + stc.top()) != TI_NULLIDX)
				{
					lexTbl.idxTI = IsId(idtable, nameFunction + stc.top());
					LT::Add(lextable, lexTbl);
				}
				else
				{
					lexTbl.idxTI = LT_TI_NULLIDX;
					LT::Add(lextable, lexTbl);
					stc.push(text);
					idTbl.id = nameFunction + stc.top();
					idTbl.iddatatype = IT::STR;
					idTbl.idtype = IT::P;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vstr->len = 0;
					idTbl.value.vstr->str[0] = '\0';
					IT::Add(idtable, idTbl);
				}
				ClearStack
				flagSTR = false;
			}

			return true;
		}

		if (flagFUNC && (flagINT || flagSTR) && !flagBodyFUNC) //функция
		{
			if (flagINT)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				stc.push(text);

				if (IT::IsId(idtable, stc.top()) != TI_NULLIDX)
				{
					lexTbl.idxTI = IsId(idtable, stc.top());
					LT::Add(lextable, lexTbl);
				}
				else
				{
					lexTbl.idxTI = LT_TI_NULLIDX;
					LT::Add(lextable, lexTbl);
					idTbl.id = stc.top();
					nameFunction = stc.top();
					idTbl.iddatatype = IT::INT;
					idTbl.idtype = IT::F;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vint = 0;
					IT::Add(idtable, idTbl);
				}
				ClearStack
				flagINT = false;
			}

			if (flagSTR)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				stc.push(text);

				if (IT::IsId(idtable, stc.top()) != TI_NULLIDX)
				{
					lexTbl.idxTI = IsId(idtable, stc.top());
					LT::Add(lextable, lexTbl);
				}
				else
				{
					lexTbl.idxTI = LT_TI_NULLIDX;
					LT::Add(lextable, lexTbl);
					idTbl.id = stc.top();
					nameFunction = stc.top();
					idTbl.iddatatype = IT::STR;
					idTbl.idtype = IT::F;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vstr->len = 0;
					idTbl.value.vstr->str[0] = '\0';
					IT::Add(idtable, idTbl);
				}
				ClearStack
				flagSTR = false;
			}

			return true;
		}

		if (flagSTR && flagEQUAL) //string str = 'hello'; 
		{
			if (IsStrokeOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);

				if (IT::IsId(idtable, stc.top()) == TI_NULLIDX)
				{
					idTbl.id = stc.top();
					ClearStack
					idTbl.iddatatype = IT::STR;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vstr->len = text.size();
					idTbl.value.vstr->str[text.size()] = (char)text.c_str();
					IT::Add(idtable, idTbl);
				}
			}

			else
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;

				if (IT::IsId(idtable, stc.top()) != TI_NULLIDX)
				{
					lexTbl.idxTI = IsId(idtable, stc.top());
					LT::Add(lextable, lexTbl);
				}
				else
				{
					lexTbl.idxTI = LT_TI_NULLIDX;
					LT::Add(lextable, lexTbl);
					idTbl.id = stc.top();
					idTbl.iddatatype = IT::STR;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vstr->len = 0;
					idTbl.value.vstr->str[0] = '\0';
					IT::Add(idtable, idTbl);
				}
				ClearStack
			}

			flagSTR = false;
			flagEQUAL = false;
			return true;
		}

		if (text == " ")
		{
			return true;
		}

		if (flagINT && flagEQUAL) //int a = 5; (флаг int и равно)
		{
			if (IsNumberOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);

				if (IT::IsId(idtable, stc.top()) == TI_NULLIDX)
				{
					idTbl.id = stc.top();
					ClearStack
					idTbl.iddatatype = IT::INT;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vint = stoi(text);
					IT::Add(idtable, idTbl);
				}
			}
			else
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;

				if (IT::IsId(idtable, stc.top()) != TI_NULLIDX)
				{
					lexTbl.idxTI = IsId(idtable, stc.top());
					LT::Add(lextable, lexTbl);
				}

				else
				{
					lexTbl.idxTI = LT_TI_NULLIDX;
					LT::Add(lextable, lexTbl);
					idTbl.id = stc.top();
					idTbl.iddatatype = IT::INT;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vint = 0;
					IT::Add(idtable, idTbl);
				}
				ClearStack
			}
			flagINT = false, flagEQUAL = false;
			return true;
		}

		if (flagEQUAL)			//a = 10 || a = 'hello' (флаг равно)
		{
			if (IsNumberOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);

				if (IT::IsId(idtable, stc.top()) != TI_NULLIDX)
				{
					idTbl.id = "L" + std::to_string(countLiteral);
					idTbl.iddatatype = IT::INT;
					idTbl.idtype = IT::L;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vint = stoi(text);
					IT::Add(idtable, idTbl);
					countLiteral++;
				}

				else
				{
					idTbl.id = stc.top();
					idTbl.iddatatype = IT::INT;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vint = stoi(text);
					IT::Add(idtable, idTbl);

				}
				ClearStack
			}

			else if (IsStrokeOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);

				if (IT::IsId(idtable, stc.top()) != TI_NULLIDX)
				{
					//------------
					idTbl.id = "L" + std::to_string(countLiteral);
					idTbl.iddatatype = IT::STR;
					idTbl.idtype = IT::L;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vstr->len = text.size();
					text.copy(idTbl.value.vstr->str, text.size() + 1);
					IT::Add(idtable, idTbl);
					countLiteral++;
				}
				else
				{
					idTbl.id = stc.top();
					idTbl.iddatatype = IT::STR;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vstr->len = text.size();
					text.copy(idTbl.value.vstr->str, text.size() + 1);
					IT::Add(idtable, idTbl);
				}
				ClearStack
			}

			else
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);
			}
			ClearStack
			flagEQUAL = false;
			return true;
		}

		if (flagPrint && IsIncludeSingleQuoteOrNot(text))
		{
			countSingleQuote++;
		}

		if (flagPrint && countSingleQuote != 0)
		{
			print = print + text + " ";

			if (IsStrokeOrNot(print))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);

				idTbl.id = "L" + std::to_string(countLiteral);
				idTbl.iddatatype = IT::STR;
				idTbl.idtype = IT::L;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vstr->len = print.size() - 1;
				print.copy(idTbl.value.vstr->str, print.size());
				IT::Add(idtable, idTbl);
				flagPrint = false;
				print = "";
				countLiteral++;
				countSingleQuote = 0;
			}

			return true;
		}

		if ((flagINT || flagSTR) && (flagFUNC||flagMAIN) && flagBodyFUNC)
		{
			lexTbl.lexema = LEX_ID;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			stc.push(text);
			return true;
		}

		else if (!flagINT && !flagSTR && (flagFUNC || flagMAIN) && flagBodyFUNC)
		{
			lexTbl.lexema = LEX_ID;
			lexTbl.sn = nLine;
			lexTbl.idxTI = LT_TI_NULLIDX;
			LT::Add(lextable, lexTbl);
			stc.push(text);
			return true;
		}

		if ((flagINT || flagSTR) && !flagEQUAL)
		{
			if (flagINT)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				stc.push(text);
				if (IT::IsId(idtable, stc.top()) != TI_NULLIDX)
				{
					lexTbl.idxTI = IsId(idtable, stc.top());
					LT::Add(lextable, lexTbl);
				}
				else
				{
					lexTbl.idxTI = LT_TI_NULLIDX;
					LT::Add(lextable, lexTbl);
					
				}
				
			}

			if (flagSTR)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				stc.push(text);
				if (IT::IsId(idtable, stc.top()) != TI_NULLIDX)
				{
					lexTbl.idxTI = IsId(idtable, stc.top());
					LT::Add(lextable, lexTbl);
				}
				else
				{
					lexTbl.idxTI = LT_TI_NULLIDX;
					LT::Add(lextable, lexTbl);	
				}
			}

			return true;
		}

		if (!flagINT && !flagSTR && !flagFUNC)
		{
			lexTbl.lexema = LEX_ID;
			lexTbl.sn = nLine;

			if (IT::IsId(idtable, text) != TI_NULLIDX)
			{
				lexTbl.idxTI = IsId(idtable, text);
				LT::Add(lextable, lexTbl);
			}

			else
			{
				lexTbl.idxTI = LT_TI_NULLIDX;
				LT::Add(lextable, lexTbl);
			}
			stc.push(text);
			return true;
		}

		else
			stc.push(text);

		return false;
	}

	bool IsNumberOrNot(std::string text)
	{
		int sizeText = text.size();
		int correctNum = 0;

		for (auto t : text)
		{
			for (int i = 0; i < 11; i++)
			{
				if (t == arrNumber[i])
				{
					correctNum++;
				}
			}
		}
		if (correctNum == sizeText)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsStrokeOrNot(std::string text)
	{
		int countOfSymbol = 0;
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] == '\'')
			{
				countOfSymbol++;
			}
		}

		if (countOfSymbol == 2)
		{
			return true;
		}

		return false;
	}

	bool IsIncludeSingleQuoteOrNot(std::string text)
	{
		int countOfSymbol = 0;
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] == '\'')
			{
				countOfSymbol++;
			}
		}

		if (countOfSymbol == 1)
		{
			return true;
		}

		return false;
	}
}

