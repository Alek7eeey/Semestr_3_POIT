#pragma once
#pragma once
#define IN_MAX_LEN_TEXT 1024*1024
#define IN_CODE_ENDL '\n'
// ������������ ������ ��������� ���� = 1MB
// ������ ����� ������
// ������� �������� ������� ����������, ������ = ��� (Windows-1251) �������
// �������� IN::F - ����������� ������, IN::T - ����������� ������, IN::I -������������ (�� �������),
//���� 0 <= �������� < 256 - �� �������� ������ ��������
#define IN_CODE_TABLE 
namespace In
{
    struct IN    // �������� ������
    {
        enum { T = 1024, F = 2048, I = 4096 }; // T - ���������� ������, F - ������������, I - ������������, ����� ��������  
        int size; // ������ ��������� ����
        int lines; // ���������� �����
        int ignor; // ���������� ����������������� ��������
        unsigned char* text; // �������� ��� (Windows - 1251)
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
        }; // ������� ��������: �, F, I ����� ��������

        IN()
        {
            code[65] = code[67] = code[69] = code[72] = code[75] = code[76] = code[78] = code[79] = code[82] = code[83] = code[86] = code[89] = code[97] = code[99] = code[101] = code[104] = code[107] = code[110] = code[111] = code[114] = code[115] = code[118] = code[121]
			= code[192] = code[194] = code[197] = code[202] = code[203] = code[205] = code[206] = code[208] = code[209] = code[215] = code[224] = code[226] = code[229] = code[233] = code[201] = code[234] = code[235]
			= code[237] = code[238] = code[240] = code[241] = code[247] = code[48] = code[49] = code[50] = code[51] = code[57] = code[7] = code[183] = code[32] = IN::T;
			code[192] = (unsigned char)'-';
        }
    };
    IN getin(wchar_t infile[]);  // ������ � ��������� ������� �����
}