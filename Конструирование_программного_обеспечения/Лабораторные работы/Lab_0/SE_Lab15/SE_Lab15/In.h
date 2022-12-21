#pragma once
#pragma once
#define IN_MAX_LEN_TEXT 1024*1024
#define IN_CODE_ENDL '\n'
// максимальный размер исходного кода = 1MB
// символ конца строки
// таблица проверки входной информации, индекс = код (Windows-1251) символа
// значения IN::F - заперщенный символ, IN::T - разрешенный символ, IN::I -игнорировать (не вводить),
//если 0 <= значение < 256 - то вводится данное значение
#define IN_CODE_TABLE 
namespace In
{
    struct IN    // исходные данные
    {
        enum { T = 1024, F = 2048, I = 4096 }; // T - допустимый символ, F - недопустимый, I - игнорировать, иначе заменить  
        int size; // размер исходного кода
        int lines; // количество строк
        int ignor; // количество проигнорированных символов
        unsigned char* text; // исходный код (Windows - 1251)
        int code[256] =
        {
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::I, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::I, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,

          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          '-', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F
        }; // таблица проверки: Т, F, I новое значение

        IN()
        {
            code[65] = code[67] = code[69] = code[72] = code[75] = code[76] = code[78] = code[79] = code[82] = code[83] = code[86] = code[89] = code[97] = code[99] = code[101] = code[104] = code[107] = code[110] = code[111] = code[114] = code[115] = code[118] = code[121]
			= code[192] = code[194] = code[197] = code[202] = code[203] = code[205] = code[206] = code[208] = code[209] = code[215] = code[224] = code[226] = code[229] = code[233] = code[201] = code[234] = code[235]
			= code[237] = code[238] = code[240] = code[241] = code[247] = code[48] = code[49] = code[50] = code[51] = code[57] = code[7] = code[183] = code[32] = IN::T;
			code[192] = (unsigned char)'-';
        }
    };
    IN getin(wchar_t infile[]);  // ввести и проверить входной поток
}