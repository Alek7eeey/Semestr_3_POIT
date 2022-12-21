#pragma once

#include "stdafx.h"


class AsmConvenrter
{
public:
	Data data;
	char* dataPath;

	AsmConvenrter( Data data){
		this->data = data;
	}

	void Invoke();

private:

	std::ofstream file;
};