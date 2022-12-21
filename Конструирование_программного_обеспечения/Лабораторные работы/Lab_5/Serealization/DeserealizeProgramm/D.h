#pragma once

#include "stdafx.h"


class Deserializer
{
public:

	Data* data;
	

	Deserializer(Data* data) {
		this->data = data;
	}

	void Invoke();

private:

	std::ifstream file;
};
