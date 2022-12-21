#pragma once

#define		LEXEMA_FIXSIZE 1			//������������� ������ �������
#define		LT_MAXSIZE 4096		//������������ ���-�� ����� � ������� ������
#define		LT_TI_NULLIDX 0xffffffff	//��� �������� ������� ���������������
#define		LEX_INTEGER 't'			//������� ��� integer
#define		LEX_STRING 't'			//������� ��� string
#define		LEX_ID 'i'			//������� ��� ��������������
#define		LEX_LITERAL 'l'			//������� ��� ��������
#define		LEX_FUNCTION 'f'			//������� ��� function
#define		LEX_DECLARE 'd'			//������� ��� declare
#define		LEX_RETURN 'r'			//������� ��� return
#define		LEX_PRINT 'p'			//������� ��� print
#define		LEX_SEMICOLON ';'			//������� ��� ;
#define		LEX_COMMA ','			//������� ��� ,
#define		LEX_LEFTBRACE '{'			//������� ��� {
#define		LEX_BRACELET '}'			//������� ��� }
#define		LEX_LEFTTHESIS '('			//������� ��� (
#define		LEX_RiGHTHESIS ')'			//������� ��� )
#define		LEX_PLUS '+'			//������� ��� +
#define		LEX_MINUS '-'			//������� ��� -
#define		LEX_STAR '*'			//������� ��� *
#define		LEX_DIRSLASH '/'			//������� ��� /
#define		LEX_MAIN 'm'			//������� ��� main
#define		LEX_RAVNO '='			//������� ��� ����� =

namespace LT	//������� ������
{
	struct Entry
	{
		char lexema; //�������
		int sn;	//����� ������ � �������� ������
		int idxTI; //������ � ������� �������������� ��� LT_TI_NULLIDX
		int priority;
	};

	struct LexTable //��������� ������� ������
	{
		int maxsize;  //������� ������� ������ < LT_MAXSIZE
		int size;	  //������� ������ ������� ������ < maxsize
		Entry* table;  //������ ����� ������� ������
	};

	LexTable Create		//������� ������� ������
	(
		int size	//������� ������� ������ < LT_MAXSIZE
	);

	void Add	//�������� ������ � ������� ������
	(
		LexTable& lextable,  //��������� �������� ������
		Entry entry		//������ �������� ������
	);

	Entry GetEntry  //�������� ������ ������� ������
	(
		LexTable& lextable,		//��������� ������� ������
		int n				//����� ���������� ������
	);

	void Delete(LexTable& lextable);	//������� ������� ������ (���������� ������)
}