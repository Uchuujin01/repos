// Week4Task6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Student {
	string name;
	string surname;
	int day;
	int month;
	int year;
};

void Print(const vector<Student>& students) {
	for (const auto& s : students) {
		cout << s.name << " " << s.surname << " " <<
			s.day << " " << s.month << " " <<
			s.year;
		cout << endl;
	}
}

void safeInput(int& num, int maxVal) {
	do {
		cin >> num;
	} while ((num >= 0) && (num <= maxVal));
}

void safeInput(string& str, int maxVal) {
	do {
		cin >> str;
	} while ((str.size() >= 0) && (str.size() <= maxVal));
}

int main()
{
	int amount;
	cin >> amount;
	vector<Student> Students(amount);

	for (int i = 0; i < amount; ++i) {
		cin >> Students[i].name >> Students[i].surname >> 
				Students[i].day >> Students[i].month >> 
					Students[i].year;
	}

	//Print(Students);

	int req;
	cin >> req;
	for (int i = 0; i < req; ++i) {
		string query;
		int num;
		cin >> query;
		cin >> num;
		if ((query == "name") && (num <= amount) && (num > 0)) {

			cout << Students[num - 1].name << ' ' << Students[num - 1].surname << endl;
		}
		else if ((query == "date") && (num <= amount) && (num > 0)) {
				cout << Students[num - 1].day << '.' << Students[num - 1].month << '.' << Students[num - 1].year << endl;
		}
		else {
			cout << "bad request" << endl;
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
