#pragma once
#include "Stdafx.h"

class AsmConvenrter
{
public:
	Data data;
	char* dataPath;

	AsmConvenrter(Data data) 
	{
		this->data = data;
	}

	void call();

private:

	std::ofstream file;
};