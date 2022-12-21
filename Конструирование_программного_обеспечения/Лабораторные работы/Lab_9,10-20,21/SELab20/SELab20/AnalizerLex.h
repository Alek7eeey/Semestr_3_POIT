#pragma once
#include <stack>

namespace AnalizerLex
{
	void LexAnalize(In::IN in,
		LT::LexTable& lextable,
		IT::IdTable& idtable);

	bool FillingTables(std::string text,
		LT::LexTable& lextable,
		IT::IdTable& idtable,
		std::stack <std::string>& stc,
		int nLine);
	bool IsNumberOrNot(std::string text);
	bool IsStrokeOrNot(std::string text);
	bool IsIncludeSingleQuoteOrNot(std::string text);

	/*bool NewStroke(char symb);*/

} 
