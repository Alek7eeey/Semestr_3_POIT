#pragma once
#define	ID_MAXSIZE		5	//максимальное кол-во символов в идентификаторе
#define TI_MAXSIZE		4096	//максимальное кол-во строк в таблице идентификаторов
#define	TI_INT_DEFAULT	0x00000000	//значение по умолч. для типа Integer
#define TI_STR_DEFAULT	0x00 //значение по умолч. для типа string
#define	TI_NULLIDX		0xffffffff	//нет элемента таблицы идентификаторов
#define TI_STR_MAXSIZE	255

namespace IT		//таблица идентификаторов
{
	enum IDDATATYPE { INT = 1, STR = 2 }; //типы данных идентифиакторов: integer, string
	enum IDTYPE //тип идентификатора
	{
		V=1, //переменная
		F=2, //функция
		P=3, //параметр
		L=4 //литерал
	};

	struct Entry  //строка тамблицы идентифиакторов
	{
		int idxfirstLE; //индекс первой строки в таблице лексем
		std::string id; //идентификатор (автоматически усекается для ID_MAXSIZE)
		IDDATATYPE iddatatype; //тип данных
		IDTYPE idtype; //тип идентификатора

		union
		{
			int vint;		//значение integer
			struct
			{
				int len;		//кол-во символов в string
				char str[TI_STR_MAXSIZE - 1];	//символы string
			}vstr[TI_STR_MAXSIZE]; //значение string

		} value;	//значение идентифиактора 
	};

	struct IdTable	//экземпляр тамблицы идентификаторов
	{
		int maxsize;		//ёмкость таблицы идентификаторов < TI_MAXSIZE
		int size;			//текущий размер таблицы идентификаторов < maxsize
		Entry* table;		//массив строк таблицы идентификаторов	
	};

	IdTable Create		//создать таблицу идентификаторов 
	(
		int size		//ёмкость таблицы идентифиакторов < TI_MAXSIZE
	);

	void Add	//добавить строку в таблицу идентификаторов
	(
		IdTable& idtable,		//экземпляр таблицы идентификаторов
		Entry entry				//строка таблицы идентификаторов
	);

	Entry GetEntry		//получить строку таблицы идентификаторов
	(
		IdTable& idtable,	//экземпляр таблицы идентификаторов
		int n				//номер получаемой строки
	);

	int IsId		//возврат; номер строки (если есть), TI_NULLIDX (если есть)
	(
		IdTable& idtable,		//экземпляр таблицы идентификаторов
		std::string id		//идентификатор
	);
	void Delete(IdTable& idtable);		//удалить таблицу лексем (освободить память)
}