#include <iostream>
#include <Windows.h>
#pragma warning(disable: 4996)


extern "C"
{
	int lenght_str(char* str)										//длина строки
	{
		return strlen(str);
	}

	int write_int(int p)											//вывод числа
	{
		std::cout << p << std::endl;
		return 0;
	}

	int write_str(char* str)										//вывод строки
	{
		setlocale(LC_ALL, "rus");
		std::cout << str << std::endl;
		return 0;
	}


	char* copy_str(char* str1, char* str2, int count)
	{
		int i;
		str1 = (char*)malloc(count);
		for (i = 0; i<count; i++) {
			str1[i] = str2[i];
		}
		str1[i] = '\0';
		
		return str1;
	}
}