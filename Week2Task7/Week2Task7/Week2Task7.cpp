// Week2Task7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int Average(vector<int>& vect)
{
	int sum = 0;
	int i = 0;
	for (int x : vect) {
		sum += x;
		i++;
	}
	return sum / i;
}

void PrintDays(vector<int>& vect)
{
	int sumOut = 0;
	vector<int> indexDaysOut;
	int average = Average(vect);
	for (int i = 0; i < vect.size(); ++i) {
		if (vect[i] > average) {
			indexDaysOut.push_back(i);
			sumOut++;
		}	
	}
	cout << sumOut << endl;
	for (int d : indexDaysOut) {
		cout << d << " ";
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> days(n);
	for (int& d : days) {
		cin >> d;
	}

	PrintDays(days);

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
