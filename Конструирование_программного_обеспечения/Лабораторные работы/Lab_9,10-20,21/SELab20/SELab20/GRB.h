#pragma once
#include "Error.h"

typedef short GRBALPHABET;	// ������� �������� ���������� ��������� > 0,����������� < 0

namespace GRB
{
	struct Rule //������� � ���������� �������
	{
		GRBALPHABET nn; //���������� (����� ������ �������) < 0
		int iderror; //�������������� ���������������� ���������
		short size; //���������� ������� - ������ ������ ������� 

		struct Chain	//�������(������ ����� �������)
		{
			short size; //����� �������
			GRBALPHABET* chainOfTerm_nTerm; //������� ���������� ( >0 ) � ������������ ( <0 )

			Chain() { this->size = 0; this->chainOfTerm_nTerm = 0; };

			Chain(
				short symbolCount, //���-�� �������� � �������
				GRBALPHABET s, ...); //������� (�������� ��� ����������)

			char* getCChain(char* b);		//�������� ������ ������� �������
			static GRBALPHABET T(char t) { return GRBALPHABET(t); } //��������
			static GRBALPHABET N(char n) { return -GRBALPHABET(n); } //�� ��������
			static bool isT(GRBALPHABET s) { return s > 0; } //�������� ?
			static bool isN(GRBALPHABET s) { return s < 0; } //����������?
			static char alphabet_to_char(GRBALPHABET s) { return (isT(s) ? char(s) : char(-s)); } //GRBALPHABET->char
		}*chains; //������ ������� - ������ ������ �������

		Rule()
		{
			this->nn = 0x00;
			this->size = 0;
			this->chains = nullptr;
			this->iderror = -1;
		}

		Rule(GRBALPHABET pnn, //���������� (<0)
			int iderror, //������������� ���������������� ��������� (ERROR)
			short psize, //���-�� ������� - ������ ������ �������
			Chain c, ...); //��������� ������� - ������ ������ �������

		char* getCRule( //�������� ������� � ���� N-> ������� (��� ����������)
			char* b, //�����
			short nchain); //����� ������� (������ �����) � �������

		short getNextChain(	//�������� ��������� �� j��������� �������, ������� � ����� ��� -1
			GRBALPHABET t,	//������ ������ �������
			Rule::Chain& pchain,	//������������ �������
			short j);	//����� �������
	};

	struct Greibach // ���������� �������
	{
		short size;	//���-�� ������
		GRBALPHABET startN;		//��������� ������
		GRBALPHABET stbottomT;  //��� �����
		Rule* rules;	//��������� ������

		Greibach()
		{
			this->size = 0;
			this->startN = 0;
			this->stbottomT = 0;
			this->rules = 0;
		};
		Greibach(GRBALPHABET pstartN,	//��������� ������
			GRBALPHABET pstbottomT,	//��� �����
			short psize,	//���-�� ������
			Rule r, ...);	//�������

		short getRule(		//�������� �������, ������������ ����� ������� ��� -1
			GRBALPHABET pnn,	//����� ������ �������
			Rule& prule);		//������������ ������� ����������

		Rule getRule(short n);	//�������� ������� �� ������
	};

	Greibach getGreibach();		//�������� ����������
}