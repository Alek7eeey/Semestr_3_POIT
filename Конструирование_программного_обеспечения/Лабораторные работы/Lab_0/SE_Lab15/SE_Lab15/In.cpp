#include "stdafx.h"
#include "In.h"
#include "Error.h"
#include <iostream>
#include <fstream>

namespace In
{
	IN getin(wchar_t infile[])
	{
		IN f;
		unsigned char ch = 'a';
		static unsigned char l[1024] = "";
		int line = 0, position = 0, size = 0, ignor = 0, i = 0, pr = 0;
		std::ifstream in(infile);
		if (in.fail() == 0)
		{
			ch = in.get();
			while (pr <= IN_MAX_LEN_TEXT)
			{
				if (in.eof())
				{
					l[i] = '\0';
					break;
				}
				if (ch == ((unsigned char)'\n'))
				{
					position = 0;
					line++;
				}
				if (f.code[(unsigned char)ch] == IN::T)
				{
					position++;
					l[i] = ch;
					i++;
				}
				else if (f.code[(unsigned char)ch] == IN::F)
				{
					throw ERROR_THROW_IN(111, line, position);
				}
				else if (f.code[(unsigned char)ch] == IN::I)
				{
					ignor++;
				}
				else
				{
					l[i] = f.code[(unsigned char)ch];
					i++;
				}

				ch = in.get();
			}

			in.close();
			f.size = i;
			f.text = l;
			f.lines = line;
			f.ignor = ignor;

		}

		else
		{
			throw ERROR_THROW(110);
		}

		return f;
	}
};
