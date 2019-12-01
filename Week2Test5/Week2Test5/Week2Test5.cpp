// Week2Test5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v)
{
		vector<int> revV;
		for (int i = v.size(); i > 0; --i) {
			revV.push_back(v.at(i - 1));
		}
		v = revV;

		//void Reverse(vector<int>& v) {
		//	int n = v.size();  // для удобства сохраним размер вектора в переменную n
		//	for (int i = 0; i < n / 2; ++i) {
		//		// элемент с индексом i симметричен элементу с индексом n - 1 - i
		//		// поменяем их местами с помощью временной переменной tmp
		//		int tmp = v[i];
		//		v[i] = v[n - 1 - i];
		//		v[n - 1 - i] = tmp;
		//	}
		//}
}

int main()
{
	vector<int> numbers = { 1, 5, 3, 4, 2 };
	Reverse(numbers);
	for (auto x : numbers) {
		cout << x;
	}
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
