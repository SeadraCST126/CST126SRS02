// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cassert>


using std::cin;
using std::cout;
using std::setw;


int main()
{
	auto namelist = new char*[5];
	char name[258] {};
	auto length = 5;
	auto i = 0;

	while (cin.good())
	{
		auto const check = cin.peek();
		//is.good(); use this!
		//this isnt setting the break point when i need it to
		//use peak to peak ahead for '\n'
		if (check == '\n')
		{
			while (i >= 0)
			{
				cout << namelist[--i];
				delete[] namelist[i];
			}
		}
		cin >> setw(257) >> name;
		auto heapName = new char[strlen(name) + 1];
		strcpy(heapName, name);
		namelist[i] = heapName;
		assert(i <= length);
		++i;
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
	}
	delete[] namelist;
    return 0;
}

