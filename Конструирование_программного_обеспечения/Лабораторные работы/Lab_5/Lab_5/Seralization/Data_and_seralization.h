#pragma once
#include "stdafx.h"

struct Data
{
	int IntNum = 6;
	const wchar_t *WcharVal = L"Hello";
};

class Serialize
{
public:
	Data data;
	Serialize(Data data): data(data)
	{

	}

	void call();

private:
	std::ofstream file;
};

