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
	//auto** namelist  = new char*[5]{};
	auto namelist = new char[5];
	auto name = new char[257];
	auto length = 5;
	auto i = 0;


	while ( i < length)
	{
		cin >> setw(256) >> name;
		strcpy(namelist, name);
		namelist = name;
		++i;
	}
	//create temp array from old namelist array
	//char temp = new char[sizeof namelist * 2];
	//delete[] namelist;
	//create new namelist array
	//auto* namelist = new char[10];
	while(i > 0)
	{
		cout << namelist;
			--i;
	}

	delete[] name;
	delete[] namelist;
    return 0;
}

