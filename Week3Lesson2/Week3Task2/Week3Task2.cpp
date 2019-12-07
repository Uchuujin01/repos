// Week3Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void Print(vector<string>& v) {
	for (auto i : v) {
		cout << i << " ";
	}
}

int main()
{
	int n;
	cin >> n;
	vector<string> vect(n);

	for (int i = 0; i < n; ++i) {
		cin >> vect[i];
	}
	sort(begin(vect), end(vect), [](string str1, string str2) {
		for (char& s : str1) {
			if ((s < 'a') && (s > '9')) {
				s += 0x20;
			}
		}
		for (char& s : str2) {
			if ((s < 'a') && (s > '9')) {
				s += 0x20;
			}
		}

		return str1 < str2;
		});
	Print(vect);
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
