#include <iostream>
#include <locale>
#include <cwchar>

#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "Rus");

	std::cout << " --- ТЕСТ IN::getin --- " << std::endl << std::endl;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		std::cout << in.text << std::endl;
		std::cout << "Всего символов: " << in.size << std::endl;
		std::cout << "Всего строк: " << in.lines - 1 << std::endl;
		std::cout << "Пропущенно: " << in.ignor << std::endl;
	}
	catch (Error::ERROR e) {
		std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	};

	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"Тест:", (char*)"без ошибок\n", "");
		Log::WriteLine(log, (wchar_t*)L"Тест:", (wchar_t*)L"без ошибок\n", L"");
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