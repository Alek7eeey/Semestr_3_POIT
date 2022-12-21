#pragma once
#include "stdafx.h"

struct Data
{
	int IntNum = 6;
	const wchar_t* WcharVal;

};

class Deserializer
{
public:

	Data* data;

	Deserializer(Data* data) 
	{
		this->data = data;
	}

	void call();

private:

	std::ifstream file;
};
