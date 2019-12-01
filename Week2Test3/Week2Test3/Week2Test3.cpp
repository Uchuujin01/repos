// Week2Test3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
using namespace std;

void UpdateIfGreater(int first, int& second) {
	
	if (first > second) {
		second = first;
	}
}

int main()
{
	//int a = 4;
	//int b = 2;
	//cin >> a >> b;
	/*UpdateIfGreater(a, b);
	cout << "a = " << a << endl << "b = " << b;*/
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
