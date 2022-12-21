// lab.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include "stdafx.h"
using namespace std;
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

	//���� getin
	std::cout << " --- ���� IN::getin --- " << std::endl << std::endl;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		std::cout << in.text << std::endl;
		std::cout << "����� ��������: " << in.size << std::endl;
		std::cout << "����� �����: " << in.lines << std::endl;
		std::cout << "����������: " << in.ignor << std::endl;
		std::ofstream Out(parm.out);
		Out << in.text;
		Out.close();
	}
	catch (Error::ERROR e) {
		std::cout << "������ " << e.id << ": " << e.message << std::endl << std::endl;
	};

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


