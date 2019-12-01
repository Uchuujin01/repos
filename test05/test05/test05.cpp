// test05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	double n, a, b, x, y;
	cin >> n >> a >> b >> x >> y;

	vector<double> values = { n, a, b };
	sort(values.begin(), values.end());


	if (values[0] == n) {
		cout << n;
	}
	else if (values[1] == n) {
		if (values[0] == a) {
			cout << n - (n * x / 100);
		}
		else {
			cout << n - (n * y / 100);
		}
	}
	else if (values[2] == n) {
		if (values[1] == a) {
			cout << n - (n * x / 100);
		}
		else {
			cout << n - (n * y / 100);
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
