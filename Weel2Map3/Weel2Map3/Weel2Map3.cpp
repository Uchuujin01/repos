// Weel2Map3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<int, string> m = { {1, "odd"}, {2, "even"}, {1, "one"} };
	m[2] = "two";
	//for (auto x : m) {
	//	cout << x.second << " ";
	//}
	m.erase(1);
	m[3] = "three";
	m.erase(4);
	m[5] = "five";
	string s = m[6];
	cout << endl;
	cout << m.size();
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
