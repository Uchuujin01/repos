// Week2Maps1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;

void PrintMap(const map<int, string>& m) {
	cout << "Size = " << m.size() << endl;
	for (auto item : m) {
		cout << item.first << ": " << item.second << endl;
	}
}

int main()
{
	map<int, string> events;
	events[1950] = "Biarne Stroustrup's birth";
	events[1941] = "Dennis Ritchie's birth";
	events[1970] = "UNIX epoch start";

	PrintMap(events);

	cout << events[1950] << endl;

	events.erase(1970);
	PrintMap(events);

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
