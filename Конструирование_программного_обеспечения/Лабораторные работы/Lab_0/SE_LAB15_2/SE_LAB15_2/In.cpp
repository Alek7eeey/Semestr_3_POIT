#include "stdafx.h"
#include "In.h"
#include "Error.h"
#include <iostream>
#include <fstream>
namespace In
{
	bool check(char symb)
	{
		char stopSymbs[] = ",;(){}[]+-*/>>";

		for (short i = 0; i < strlen(stopSymbs); i++)
		{
			if (symb == stopSymbs[i])
			{
				return true;
			}
		}

		return false;
	}

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
					l[i] = '\n';
					i++;
				}

				else if (f.code[(unsigned char)ch] == IN::T)
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

			int size = sizeof(l) / sizeof(unsigned char);
			static unsigned char newl[1024] = "";
			int nj = 0;
			int k = 0;
			int countForCheck = 0;
			for (short i = 0; i < size; i++)
			{
				countForCheck = 0;
				while (check(l[i]) == true)
				{
					countForCheck++;
					if (countForCheck == 1)
					{
						if (l[i - 1] == ' ' && l[i + 1] == ' ')
						{
							newl[nj] = l[i];
							nj++;
						}

						else if (l[i] == '>' && l[i + 1] == '>')
						{
							i++;
							continue;
						}

						else if (l[i - 1] == ' ' && l[i + 1] != '\n' && l[i + 1] != '\0')
						{
							newl[nj] = l[i];
							newl[nj + 1] = ' ';
							nj += 2;
						}

						else if (l[i - 1] == ' ' && l[i + 1] == '\n')
						{
							newl[nj] = l[i];
							newl[nj + 1] = '\n';
							nj += 2;
							i++;
						}

						else if (l[i - 1] == ' ' && l[i + 1] == '\0')
						{
							newl[nj] = l[i];
							newl[nj + 1] = '\0';
							nj += 2;
							i++;
						}

						else if (l[i + 1] == ' ')
						{
							newl[nj] = ' ';
							newl[nj + 1] = l[i];
							nj += 2;
						}

						else if (l[i - 1] != ' ' && l[i + 1] != ' ' && l[i + 1] != '\n' && l[i + 1] != '\0')
						{
							newl[nj] = ' ';
							newl[nj + 1] = l[i];
							newl[nj + 2] = ' ';
							nj += 3;
						}

						else if (l[i - 1] != ' ' && l[i + 1] != ' ' && l[i + 1] == '\n' && l[i - 1] == '\n')
						{
							newl[nj] = l[i];
							newl[nj + 1] = '\n';
							nj += 2;
							i++;
						}

						else if (l[i - 1] != ' ' && l[i + 1] != ' ' && l[i + 1] == '\n')
						{
							newl[nj] = ' ';
							newl[nj + 1] = l[i];
							newl[nj + 2] = '\n';
							nj += 3;
							i++;
						}

						else if (l[i - 1] != ' ' && l[i + 1] != ' ' && l[i + 1] == '\0')
						{
							newl[nj] = ' ';
							newl[nj + 1] = l[i];
							newl[nj + 2] = '\0';
							nj += 3;

						}
					}

					else
					{
						if (l[i + 1] == ' ')
						{
							newl[nj] = l[i];
							nj++;
						}

						else if (l[i + 1] != '\n' && l[i + 1] != '\0')
						{
							newl[nj] = l[i];
							newl[nj + 1] = ' ';
							nj += 2;
						}

						else if (l[i + 1] == '\n')
						{
							newl[nj] = l[i];
							newl[nj + 1] = '\n';
							nj += 2;
							i++;
						}

						else if (l[i + 1] == '\0')
						{
							newl[nj] = l[i];
							newl[nj + 1] = '\0';
							nj += 2;
							
						}
					}

					i++;		
				}



				if ((l[i] == ' ' && l[i+1] == ' ') || (l[i] == '\n' && l[i + 1] == '\n'))
				{
					continue;
				}

				else
				{
					newl[nj] = l[i];
					nj++;
				}
			}

			int NewSize = 0;
			for (int b = 0; b < size; b++)
			{
				if(newl[b] != '\0')
				{
					NewSize++;
				}
			}

			in.close();
			f.size = NewSize;
			f.text = newl;
			f.lines = line+1;
			f.ignor = ignor;

		}
		
		else
		{
			throw ERROR_THROW(110);
		}
		return f;
	}
};

