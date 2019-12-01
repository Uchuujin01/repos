// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void main()
{
	int c = 5;
	int a = c++;
	int b = ++c;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

