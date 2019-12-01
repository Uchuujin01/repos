// Week2Task11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, string> countries;
	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		string query;
		cin >> query;
		if (query == "CHANGE_CAPITAL") {
			string country;
			string capital;
			cin >> country;
			cin >> capital;
			if (countries.count(country) > 0) {
				if (countries[country] == capital) {
					cout << "Country " << country << " hasn't changed its capital" << endl;
				}
				else {
					cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << capital << endl;
					countries[country] = capital;
				}
			}
			else {
				countries[country] = capital;
				cout << "Introduce new country " << country << " with capital " << countries[country] << endl;
			}
		} else if (query == "RENAME") {
			string country_old;
			string country_new;
			cin >> country_old;
			cin >> country_new;
			if ((countries.count(country_old) > 0) && (countries.count(country_new) == 0) && (country_old != country_new)) {
				
				countries[country_new] = countries[country_old];
				cout << "Country " << country_old << " with capital " << countries[country_old] << " has been renamed to " << country_new << endl;
				countries.erase(country_old);
			}
			else {
				cout << "Incorrect rename, skip" << endl;
			}
		} else if (query == "ABOUT") {
			string country;
			cin >> country;
			if (countries.count(country) > 0) {
				cout << "Country " << country << " has capital " << countries[country] << endl;
			}
			else {
				cout << "Country " << country << " doesn't exist" << endl;
			}

		} if (query == "DUMP") {
			if (countries.size() == 0) {
				cout << "There are no countries in the world" << endl;
			}
			else {
				for (auto c : countries) {
					cout << c.first << "/" << c.second << " ";
				}
				cout << endl;
			}
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
