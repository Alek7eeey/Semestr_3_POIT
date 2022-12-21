#include "stdafx.h"

using namespace std;

int main() 
{
	Data data;
	Deserializer deserializer( &data);
	deserializer.Invoke();
	AsmConvenrter assembler( data);
	assembler.Invoke();
}