// Week2Task9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
//#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	const vector<int> year = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	vector<vector<string>> month;
	int currMonthNum = 0;
	int prevMonthNum = 0;
	int commNum = 0;

		month.resize(year[currMonthNum]);

	cin >> commNum;
	vector<string> commandsIn(commNum);

	for (int i = 0; i < commNum; ++i) {
		cin >> commandsIn[i];

		if (commandsIn[i] == "ADD") {
			int dayIn;
			string task;
			cin >> dayIn;
			cin >> task;
			month[dayIn-1].push_back(task);
		}

		if (commandsIn[i] == "DUMP") {
			int dayIn;
			cin >> dayIn;
			cout << month[dayIn - 1].size() << " ";
			for (int j = 0; j < month[dayIn - 1].size(); ++j) {
				cout << month[dayIn - 1][j] << " ";
			}
			cout << endl;
		}

		if (commandsIn[i] == "NEXT") {
			prevMonthNum = currMonthNum;
			if (currMonthNum < year.size() - 1) {
				currMonthNum++;
			}
			else {
				currMonthNum = 0;
			}
				if (year[currMonthNum] < year[prevMonthNum]) {
					for (int i = year[currMonthNum]; i < year[prevMonthNum]; ++i) {
						month[year[currMonthNum] - 1].insert(end(month[year[currMonthNum] - 1]), begin(month[i]), end(month[i]));
					}
				}
				month.resize(year[currMonthNum]);
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
