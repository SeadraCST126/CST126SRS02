// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using std::cin;
using std::cout;
using std::setw;

namespace
{
	size_t output(size_t i, const char* const* const namelist)
	{
		while (i > 0)
		{
			cout << namelist[--i] << " ";
			delete[] namelist[i];
		}
		cout << std::endl;
		return i;
	}
}

int main()
{
	auto result = -1;
	auto namelist = new char*[5];
	auto length = 5;
	size_t i = 0;
	auto eof = false;

	while (cin.good())
	{
		
		const auto check = cin.peek();
		switch(check)
		{
		case EOF:
		case '\n':
			i = output(i, namelist);
			cin.ignore();
			break;

		case ' ':
			cin.ignore();
			break;

		default:
			char name[258];
			if (!(cin >> setw(257) >> name))
			{
				eof = true;
			}
			const auto name_length = strlen(name);
			if (name_length > 0)
			{
				if (i == length)
				{
					auto const temp = new char*[length * 2];
					for (auto i2 = 0; i2 < length; ++i2)
					{
						temp[i2] = namelist[i2];
					}
					length *= 2;
					delete[] namelist;
					namelist = temp;
				}
				const auto heap_name = new char[name_length + 1];
				strcpy(heap_name, name);
				namelist[i] = heap_name;
				++i;
			}
			break;
		}
	}
	output(i, namelist);
	delete[] namelist;
	if (cin.eof())
	{
		result = 0;
	}
    return result;
}