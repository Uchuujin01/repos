// Week3Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string str) {
	string revStr;
	for (int i = str.size(); i > 0; --i) {
		revStr.push_back(str.at(i - 1));
	}
	if (str == revStr) {
		return true;
	}
	else {
		return false;
	}
}

vector<string> PalindromFilter(vector<string> words, int minLength) {

	for (int i = 0; i < words.size(); ++i) {
		if ((words[i].size() < minLength) ) {
			words.erase(words.begin() + i);
			i--;
		}
		else {
			if (!IsPalindrom(words[i])) {
				words.erase(words.begin() + i);
				i--;
			}
		}
	}
	//cout << words.size();
	return words;
}

int main()
{
	vector<string> vectorStr = { {"5697649467"}, "1", "34", {"ada"}, {"asd"}, {"fjlksdfh"}, {"adada"} };
	int minLength = 5;
	for (string str : PalindromFilter(vectorStr, minLength)) {
		cout << str << endl;
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
