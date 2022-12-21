#pragma once

#define		LEXEMA_FIXSIZE 1			//фиксированный размер лексемы
#define		LT_MAXSIZE 4096		//максимальное кол-во строк в таблице лексем
#define		LT_TI_NULLIDX 0xffffffff	//нет элемента таблицы идентификаторов
#define		LEX_INTEGER 't'			//лексема для integer
#define		LEX_STRING 't'			//лексема для string
#define		LEX_ID 'i'			//лексема для идентификатора
#define		LEX_LITERAL 'l'			//лексема для литерала
#define		LEX_FUNCTION 'f'			//лексема для function
#define		LEX_DECLARE 'd'			//лексема для declare
#define		LEX_RETURN 'r'			//лексема для return
#define		LEX_PRINT 'p'			//лексема для print
#define		LEX_SEMICOLON ';'			//лексема для ;
#define		LEX_COMMA ','			//лексема для ,
#define		LEX_LEFTBRACE '{'			//лексема для {
#define		LEX_BRACELET '}'			//лексема для }
#define		LEX_LEFTTHESIS '('			//лексема для (
#define		LEX_RiGHTHESIS ')'			//лексема для )
#define		LEX_PLUS '+'			//лексема для +
#define		LEX_MINUS '-'			//лексема для -
#define		LEX_STAR '*'			//лексема для *
#define		LEX_DIRSLASH '/'			//лексема для /
#define		LEX_MAIN 'm'			//лексема для main
#define		LEX_RAVNO '='			//лексема для знака =

namespace LT	//таблица лексем
{
	struct Entry
	{
		char lexema; //лексема
		int sn;	//номер строки в исходном тексте
		int idxTI; //индекс в таблице идентификатора или LT_TI_NULLIDX
		int priority;
	};

	struct LexTable //экземпляр таблицы лексем
	{
		int maxsize;  //ёмкость таблицы лексем < LT_MAXSIZE
		int size;	  //текущий размер таблицы лексем < maxsize
		Entry* table;  //массив строк таблицы лексем
	};

	LexTable Create		//создать таблицу лексем
	(
		int size	//ёмкость таблицы лексем < LT_MAXSIZE
	);

	void Add	//добавить строку в таблицу лексем
	(
		LexTable& lextable,  //Экземпляр тамблицы лексем
		Entry entry		//строка тамблицы лексем
	);

	Entry GetEntry  //получить строку таблицы лексем
	(
		LexTable& lextable,		//экзмепляр таблицы лексем
		int n				//номер получаемой строки
	);

	void Delete(LexTable& lextable);	//удалить таблицу лексем (освободить память)
}