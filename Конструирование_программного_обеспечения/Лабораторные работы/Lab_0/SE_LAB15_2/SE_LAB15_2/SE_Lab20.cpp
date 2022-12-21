// lab.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.

#include "D:\studing\3 �������\���������������_������������_�����������\������������ ������\Lab_9,10-20,21\\SELab20\\SELab20\\stdafx.h"
#define MFST_TRACE_START std::cout << std::setw(4) << std::left<<"���"<<":" \
						<< std::setw(20) << std::left << "�������" \
						<< std::setw(30) << std::left << "������� �����" \
						<< std::setw(20) << std::left << "����" \
						<< std::endl;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	//���� error
	/*cout << "-� Error::getterror �-" << endl << endl;
	try
	{
		throw ERROR_THROW(1);
	}
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ":" << e.message << endl << endl;
	};

	cout << "-� Error::geterrorin �-" << endl << endl;
	try {
		throw ERROR_THROW_IN(111, 7, 7);
	}
	catch (Error::ERROR e)
	{
		cout <<"������ " << e.id << ":" << e.message
			<< ", ������ " << e.inext.line
			<< ", ������� " << e.inext.col << endl << endl;
	};
	*/
	//���� parm
	/*cout << "-� ���� Parm::getparam �-" << endl << endl;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log <<endl <<endl;
	}
	catch (Error::ERROR e) {
		cout << "������ " << e.id << ": " << e.message <<endl <<endl;
	}*/

	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		std::cout << in.text << std::endl;
		std::cout << "����� ��������: " << in.size << std::endl;
		std::cout << "����� �����: " << in.lines << std::endl;
		std::cout << "����������: " << in.ignor << std::endl;
		IT::IdTable idt = IT::Create(in.size);
		LT::LexTable lex = LT::Create(in.size);
		AnalizerLex::LexAnalize(in, lex, idt);
		OutFILE::WriteOutFile(argc, argv, lex, idt);
		MFST::Mfst mfst(lex, GRB::getGreibach(), parm.pars);
		mfst.start();
		mfst.savededucation();
		mfst.printRules();

		if (!startPolishNotation(lex, idt)) {
			cout << "ERROR::POLISH" << endl;
			throw ERROR_THROW(611);
		}

	}

	catch (Error::ERROR e) 
	{
		std::cout << "������ " << e.id << ": " << e.message << std::endl << std::endl;
	}

	Log::LOG log = Log::INITLOG;
	try
	{   
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"����:", (char*)"��� ������\n", "");
		Log::WriteLine(log, (wchar_t*)L"����:", (wchar_t*)L"��� ������\n", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Log::Close(log);
	}

	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
	system("pause");
	return 0;
}


