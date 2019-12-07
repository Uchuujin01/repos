// Week3Task2_solution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// считываем вектор строк
	int n;
	cin >> n;
	vector<string> v(n);
	for (string& s : v) {
		cin >> s;
	}

	// сортируем
	sort(begin(v), end(v),
		// компаратор дл€ сортировки Ч л€мбда-функци€, сравнивающа€ строки без учЄта регистра
		[](const string& l, const string& r) {
			// сравниваем лексикографически...
			return lexicographical_compare(
				// ... все символы строки l ...
				begin(l), end(l),
				// ... со всеми символами строки r ...
				begin(r), end(r),
				// ..., использу€ в качестве компаратора сравнение отдельных символов без учЄта регистра
				[](char cl, char cr) { return tolower(cl) < tolower(cr); }
			);
		}
	);

	// выводим отсортированный вектор
	for (const string& s : v) {
		cout << s << ' ';
	}

	return 0;
}


int main()
{
    std::cout << "Hello World!\n"; 
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
