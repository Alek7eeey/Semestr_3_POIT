#pragma once
#include "stdafx.h"

class Serealizer
{
public:
	Data data;

	Serealizer(Data data) :  data(data) 
	{ 

	}

	void Invoke();

private:

	std::ofstream file;

};
