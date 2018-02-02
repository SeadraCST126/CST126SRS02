// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>


using std::cin;
using std::cout;
using std::setw;


int main()
{
	auto namelist = new char[5];
	auto const name = new char[257];
	auto length = 5;
	auto i = 0;
	auto eof = false;

	while (i < length && eof == false)
	{
		cin >> setw(256) >> name;
		cout << name;
		//need to account for a null pointer
		//this isnt working as intended need to take the name list @ index i and make it = the name string
		namelist[i] = *name;
		//--------------------------------------------------------------------------
		++i;
		// need to make eof == false if its the end of the file somehow

		//--------------------------------------------------------------------------
		if (i >= length)
		{
			auto const temp = new char[length * 2];
			for (auto i2 = 0; i2 < length; ++i2)
			{
				temp[i2] = namelist[i2];
			}
			length *= 2;
			delete[] namelist;
			namelist = temp;
			delete[] temp;
		}
	}

	while(i >= 0)
	{
		cout << namelist[i];
			--i;
	}

	delete[] name;
	delete[] namelist;
    return 0;
}

