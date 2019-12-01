// Week2Task10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<char, int> BuildCharCounters(string& word) {
	map<char, int> result;

	for (char& c : word) {
		result[c]++;
	}

	return result;
}

int main()
{
	string word1, word2;
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {

		cin >> word1;
		cin >> word2;

		if (BuildCharCounters(word1) == BuildCharCounters(word2)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

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
