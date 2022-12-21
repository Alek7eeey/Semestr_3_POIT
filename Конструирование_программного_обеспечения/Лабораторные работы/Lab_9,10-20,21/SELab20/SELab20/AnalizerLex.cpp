#include "stdafx.h"
#include "AnalizerLex.h"
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
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
	static std::string print= "";
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
				FillingTables(word, lextable, idtable,stc, numbLine);
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

			word += in.text[i];

			if (in.text[i + 1] == '\0')
			{
				FillingTables(word, lextable, idtable, stc, numbLine);
				word = "";
				i++;
			}
		}   
		int k = 1;
		cout <<'\n' << k << ' ';
		for (int i = 0; i < lextable.size; i++)
		{

			if (lextable.table[i].lexema == '{')
			{
				cout << endl;
				k++;
				cout << k << ' ';
				cout << lextable.table[i].lexema;
				if (k != in.lines)
				{
					cout << endl;
					k++;
					cout << k << ' ';
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
					cout << "��� ������: INT " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t��������: " << idtable.table[i].value.vint << "\t ��� ��������������: ����������" << endl;
				}

				if (idtable.table[i].idtype == 2)
				{
					cout << "��� ������: INT " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t��������: " << idtable.table[i].value.vint << "\t ��� ��������������: �������" << endl;
				}

				if (idtable.table[i].idtype == 3)
				{
					cout << "��� ������: INT " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t��������: " << idtable.table[i].value.vint << "\t ��� ��������������: ��������" << endl;
				}

				if (idtable.table[i].idtype == 4)
				{
					cout << "��� ������: INT " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t��������: " << idtable.table[i].value.vint << "\t ��� ��������������: �������" << endl;
				}
			}

			if (idtable.table[i].iddatatype == 2)
			{
				if (idtable.table[i].idtype == 1)
				{
					cout << "��� ������: STRING " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t�����: " << idtable.table[i].value.vstr->len << "\t ��� ��������������: ����������";

					if (idtable.table[i].value.vstr->len != 0)
					{
						cout << "\t ��������: ";
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
					cout << "��� ������: STRING " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t�����: " << idtable.table[i].value.vstr->len << "\t ��� ��������������: �������";

					if (idtable.table[i].value.vstr->len != 0)
					{
						cout << "\t ��������: ";
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
					cout << "��� ������: STRING " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t�����: " << idtable.table[i].value.vstr->len << "\t ��� ��������������: ��������";
					if (idtable.table[i].value.vstr->len != 0)
					{
						cout << "\t ��������: ";
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
					cout << "��� ������: STRING " << "\t �������������: " << idtable.table[i].id << "\t ������: " << idtable.table[i].idxfirstLE
						<< "\t�����: " << idtable.table[i].value.vstr->len << "\t ��� ��������������: �������" <<"\t ��������: ";
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

	bool FillingTables (std::string text,
		LT::LexTable& lextable,
		IT::IdTable& idtable,
		stack <string>& stc,
		int nLine)
	{
		LT::Entry lexTbl;
		IT::Entry idTbl;

		if (text == "integer")
		{
			lexTbl.lexema = LEX_INTEGER;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);
			stc.push(text);
			flagINT = true;
			return true;
		}

		else if (text == "string")
		{
			lexTbl.lexema = LEX_STRING;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);
			stc.push(text);
			flagSTR = true;
			return true;
		}

		else if (text == "function")
		{
			lexTbl.lexema = LEX_FUNCTION;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);
			stc.push(text);
			flagFUNC = true;
			return true;
		}
		
		else if (text == "declare")
		{
			lexTbl.lexema = LEX_DECLARE;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);
			return true;
		}

		else if (text == "return")
		{
			lexTbl.lexema = LEX_RETURN;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);
			return true;
		}

		else if (text == "print")
		{
			lexTbl.lexema = LEX_PRINT;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);
			flagPrint = true;
			return true;
		}

		else if (text == "main")
		{
			lexTbl.lexema = LEX_MAIN;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);
			flagMAIN = true;
			nameFunction = "main";
			return true;
		}

		else if (text == ";")
		{
			lexTbl.lexema = LEX_SEMICOLON;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);
			flagENDL = true;

			if (((flagFUNC && flagBodyFUNC) || flagMAIN) && (flagINT || flagSTR) && flagENDL) //���� ������� ���� int a;
			{
				idTbl.id = nameFunction + stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
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

			if (flagINT || flagSTR) //������ ���� ��� ��� ������
			{
				idTbl.id = stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}

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
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);
			return true;
		}

		else if (text == "{")
		{
			lexTbl.lexema = LEX_LEFTBRACE;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
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
			lexTbl.idxTI = -1;
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
			lexTbl.idxTI = -1;
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
			lexTbl.idxTI = -1;
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
		lexTbl.idxTI = -1;
		LT::Add(lextable, lexTbl);
		return true;
		}

		else if (text == "-")
		{
		lexTbl.lexema = LEX_MINUS;
		lexTbl.sn = nLine;
		lexTbl.idxTI = -1;
		LT::Add(lextable, lexTbl);
		return true;
		}

		else if (text == "*")
		{
		lexTbl.lexema = LEX_STAR;
		lexTbl.sn = nLine;
		lexTbl.idxTI = -1;
		LT::Add(lextable, lexTbl);
		return true;
		}

		else if (text == "/")
		{
		lexTbl.lexema = LEX_DIRSLASH;
		lexTbl.sn = nLine;
		lexTbl.idxTI = -1;
		LT::Add(lextable, lexTbl);
		return true;
		}

		else if (text == "=")
		{
		lexTbl.lexema = LEX_RAVNO;
		lexTbl.sn = nLine;
		lexTbl.idxTI = -1;
		LT::Add(lextable, lexTbl); 
		flagEQUAL = true;

			return true;
		}

		if (text == "substr")
		{
			lexTbl.lexema = LEX_ID;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);

			idTbl.id = "substr"; 
			nameStaticFunction = "substr";
			while (!stc.empty())
			{
				stc.pop();
			}
			idTbl.iddatatype = IT::STR;
			idTbl.idtype = IT::F;
			idTbl.idxfirstLE = nLine;
			idTbl.value.vstr->len = 0;
			idTbl.value.vstr->str[0] = '\0';
			IT::Add(idtable, idTbl);
			flagSTR = false;
			flagStaticFUNC = true;
			return true;
		}

		if (text == "strlen")
		{
			lexTbl.lexema = LEX_ID;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);
			idTbl.id = "strlen";
			nameStaticFunction = "strlen";
			while (!stc.empty())
			{
				stc.pop();
			}
			idTbl.iddatatype = IT::INT;
			idTbl.idtype = IT::F;
			idTbl.idxfirstLE = nLine;
			idTbl.value.vint = 0;
			IT::Add(idtable, idTbl);
			flagINT = false;
			flagStaticFUNC = true;
			return true;
		}

		if (flagStaticFUNC && flagARG && (flagINT || flagSTR))
		{
			if (flagINT)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);

				stc.push(text);
				idTbl.id = nameStaticFunction + stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::INT;
				idTbl.idtype = IT::P;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vint = 0;
				IT::Add(idtable, idTbl);
				flagINT = false;
			}

			if (flagSTR)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);

				stc.push(text);
				idTbl.id = nameStaticFunction + stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::STR;
				idTbl.idtype = IT::P;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vstr->len = 0;
				idTbl.value.vstr->str[0] = '\0';
				IT::Add(idtable, idTbl);
				flagSTR = false;
			}

			return true;
		}

		if (((flagFUNC && flagBodyFUNC) || flagMAIN) && flagEQUAL && (flagINT||flagSTR)) //���� ������� ���� int a = 10;
		{
			if (flagINT)
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);

				stc.push(text);
				idTbl.id = nameFunction + stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}

				idTbl.iddatatype = IT::INT;
				idTbl.idtype = IT::V;
				idTbl.idxfirstLE = nLine;
				if (stoi(text)!=0)
				{
					idTbl.value.vint = stoi(text);
				}
				else
				{
					idTbl.value.vint = 0;
				}
				IT::Add(idtable, idTbl);
				flagINT = false;
			}

			if (flagSTR)
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);

				stc.push(text);
				idTbl.id = nameFunction + stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
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
				flagSTR = false;
			}
			
			return true;
		}

		if (!flagEQUAL && !flagINT && !flagSTR && IsNumberOrNot(text))
		{
			lexTbl.lexema = LEX_LITERAL;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
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

		if (!flagEQUAL && flagARG && IsNumberOrNot(text))
		{
			lexTbl.lexema = LEX_LITERAL;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
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

		if (flagEQUAL && ( (flagFUNC && flagBodyFUNC)||flagMAIN) ) //���� ������� ���� a = 10;
		{
			if (IsNumberOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);
				if (IT::IsId(idtable, nameFunction + stc.top()) != TI_NULLIDX)
				{
					//idTbl.id = "&" + nameFunction + stc.top(); //���������
					
				}
				else
				{
					idTbl.id = nameFunction + stc.top();
					while (!stc.empty())
					{
						stc.pop();
					}
					idTbl.iddatatype = IT::INT;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vint = stoi(text);
					IT::Add(idtable, idTbl);

					//------------------
					idTbl.id = "L" + std::to_string(countLiteral);
					idTbl.iddatatype = IT::INT;
					idTbl.idtype = IT::L;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vint = stoi(text);
					IT::Add(idtable, idTbl);
					countLiteral++;
				}
				
				
			}

			else if (IsStrokeOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);
				if (IT::IsId(idtable, nameFunction + stc.top()) != TI_NULLIDX)
				{
					/*idTbl.id = "&" + stc.top();*/
				}
				else
				{
					idTbl.id = nameFunction + stc.top();
					while (!stc.empty())
					{
						stc.pop();
					}
					idTbl.iddatatype = IT::STR;
					idTbl.idtype = IT::V;
					idTbl.idxfirstLE = nLine;
					idTbl.value.vstr->len = text.size();
					text.copy(idTbl.value.vstr->str, text.size() + 1);
					IT::Add(idtable, idTbl);

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
			
			}

			else
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);
			}

				flagEQUAL = false;
				return true;
		}

		if ((flagFUNC && flagARG) && (flagINT || flagSTR)) //��������� �������
		{	
			if (flagINT)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);

				stc.push(text);
				idTbl.id = nameFunction + stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::INT;
				idTbl.idtype = IT::P;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vint = 0;
				IT::Add(idtable, idTbl);
				flagINT = false;
			}

			if (flagSTR)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);

				stc.push(text);
				idTbl.id = nameFunction + stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::STR;
				idTbl.idtype = IT::P;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vstr->len = 0;
				idTbl.value.vstr->str[0] = '\0';
				IT::Add(idtable, idTbl);
				flagSTR = false;
			}

			return true;
		}

		if (flagFUNC && (flagINT || flagSTR) && !flagBodyFUNC) //������� 
		{
			if (flagINT)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);

				stc.push(text);
				idTbl.id = stc.top();
				nameFunction = stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::INT;
				idTbl.idtype = IT::F;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vint = 0;
				IT::Add(idtable, idTbl);
				flagINT = false;
			}

			if (flagSTR)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);

				stc.push(text);
				idTbl.id = stc.top();
				nameFunction = stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::STR;
				idTbl.idtype = IT::F;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vstr->len = 0;
				idTbl.value.vstr->str[0] = '\0';
				IT::Add(idtable, idTbl);
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
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);
				idTbl.id = stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::STR;
				idTbl.idtype = IT::V;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vstr->len = text.size();
				idTbl.value.vstr->str[text.size()] = (char)text.c_str();
				IT::Add(idtable, idTbl);
			}

			else
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);
				idTbl.id = stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::STR;
				idTbl.idtype = IT::V;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vstr->len = 0;
				idTbl.value.vstr->str[0] = '\0';
				IT::Add(idtable, idTbl);
			}

			flagSTR = false, flagEQUAL = false;
			return true;
		}

		if (text == " ")
		{
			return true;
		}

		if (flagINT && flagEQUAL) //int a = 5; (���� int � �����)
		{
			if (IsNumberOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);
				idTbl.id = stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::INT;
				idTbl.idtype = IT::V;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vint = stoi(text);
				IT::Add(idtable, idTbl);
			}
			else
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);
				idTbl.id = stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::INT;
				idTbl.idtype = IT::V;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vint = 0;
				IT::Add(idtable, idTbl);
			}
				flagINT = false, flagEQUAL = false;
				return true;
		}

		if (flagEQUAL)			//a = 10 || a = 'hello' (���� �����)
		{
			if(IsNumberOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);
				idTbl.id = stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::INT;
				idTbl.idtype = IT::V;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vint = stoi(text);
				IT::Add(idtable, idTbl);

				//------------

				idTbl.id = "L" + std::to_string(countLiteral);
				idTbl.iddatatype = IT::INT;
				idTbl.idtype = IT::L;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vint = stoi(text);
				IT::Add(idtable, idTbl);
				countLiteral++;
			}

			else if (IsStrokeOrNot(text))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);
				idTbl.id = stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::STR;
				idTbl.idtype = IT::V;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vstr->len = text.size();
				text.copy(idTbl.value.vstr->str, text.size()+1);
				IT::Add(idtable, idTbl);

				//------------

				idTbl.id = "L" + std::to_string(countLiteral);
				idTbl.iddatatype = IT::STR;
				idTbl.idtype = IT::L;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vstr->len = text.size();
				text.copy(idTbl.value.vstr->str, text.size()+1);
				IT::Add(idtable, idTbl);
				countLiteral++;

			}

			else
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);
			}

			flagEQUAL = false;
			return true;
		}

		if (flagPrint && IsIncludeSingleQuoteOrNot(text))
		{
			countSingleQuote++;
		}

		if (flagPrint && countSingleQuote!=0)
		{
			print = print + text + " ";

			if (IsStrokeOrNot(print))
			{
				lexTbl.lexema = LEX_LITERAL;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);

				idTbl.id = "L" + std::to_string(countLiteral);
				idTbl.iddatatype = IT::STR;
				idTbl.idtype = IT::L;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vstr->len = print.size()-1;
				print.copy(idTbl.value.vstr->str, print.size());
				IT::Add(idtable, idTbl);
				flagPrint = false;
				print = "";
				countLiteral++;
				countSingleQuote = 0;
			}

 			return true;
		}

		if (!flagINT && !flagSTR)
		{
		lexTbl.lexema = LEX_ID;
		lexTbl.sn = nLine;
		lexTbl.idxTI = -1;
		LT::Add(lextable, lexTbl);
		stc.push(text);
		//!!!����� �������� ������ ��� ������ ����������
		return true;
		}

		if ((flagINT || flagSTR) && flagFUNC && flagBodyFUNC)
		{
			lexTbl.lexema = LEX_ID;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);
			stc.push(text);
			return true;
		}

		else if (!flagINT && !flagSTR && flagFUNC && flagBodyFUNC)
		{
			lexTbl.lexema = LEX_ID;
			lexTbl.sn = nLine;
			lexTbl.idxTI = -1;
			LT::Add(lextable, lexTbl);
			stc.push(nameFunction + text);
			return true;
		}

		if ((flagINT || flagSTR) && !flagEQUAL)
		{
			if (flagINT)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);

				stc.push(text);
				idTbl.id = stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::INT;
				idTbl.idtype = IT::V;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vint = 0;
				IT::Add(idtable, idTbl);
				flagINT = false;
			}

			if (flagSTR)
			{
				lexTbl.lexema = LEX_ID;
				lexTbl.sn = nLine;
				lexTbl.idxTI = -1;
				LT::Add(lextable, lexTbl);

				stc.push(text);
				idTbl.id = stc.top();
				while (!stc.empty())
				{
					stc.pop();
				}
				idTbl.iddatatype = IT::STR;
				idTbl.idtype = IT::V;
				idTbl.idxfirstLE = nLine;
				idTbl.value.vstr->len = 0;
				idTbl.value.vstr->str[0] = '\0';
				IT::Add(idtable, idTbl);
				flagSTR = false;
			}

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

