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
	auto* namelist  = new char[][10];
	auto i = 0;
	char name[257];
	
	cin >> name;
	while (!cin.eof)
	{
		const auto length = sizeof namelist / sizeof(char);
		while (i < length)
		{
			//char name[257] = {};
			cin >> setw(256) >> name;
			//namelist[i][] = new char[name];
			i++;
		}
		//create temp array from old namelist array
		//char temp = new char[length * 2];
		delete[] namelist;
		//create new namelist array
	}
	delete[] namelist;
    return 0;
}

