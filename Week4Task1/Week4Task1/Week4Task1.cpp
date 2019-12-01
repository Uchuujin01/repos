#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void ReadAll(const string& path) {
	ifstream input(path);
	if (input.is_open()) {
		string line;
		while (getline(input, line)) {
			cout << line << endl;
		}
	}
}

void Print(const vector<string>& names, const vector<double>& values,
			int width) {
	for (const auto& n : names) {
		cout << setw(width) << n << ' ';
	}
	cout << endl;
	cout << fixed << setprecision(2);
	for (const auto& v : values) {
		cout << setw(width) << v << ' ';
	}
}

int main()
{
	vector<string> names = {"a", "b", "c"};
	vector<double> values = { 5, 0.01, 0.000005 };
	cout << setfill('.') << left;
	Print(names, values, 10);


	/*---------------------------------------------------*/

	/*const string path = "output.txt";
	ofstream output(path, ios::app);
	output << "Hello!" << endl;

	ReadAll(path);*/

	/*---------------------------------------------------*/

	//ifstream input(path);
	/*int year = 0;
	int month = 0;
	int day = 0;

	if (input) {
		input >> year;
		input.ignore(1);
		input >> month;
		input.ignore(1);
		input >> day;
		input.ignore(1);
	}

	cout << year << ' ' << month << ' ' << day;*/

	/*---------------------------------------------------*/

	/*string year;
	string month;
	string day;

	if (input) {
		getline(input, year, '-');
		getline(input, month, '-');
		getline(input, day, '-');
	}*/
	
	/*---------------------------------------------------*/

	//string line;
	/*if (input.is_open()) {
		while (getline(input, line)) {
			cout << line << endl;
		}
	}
	else {
		cout << "error!" << endl;
	}*/
	return 0;
}
