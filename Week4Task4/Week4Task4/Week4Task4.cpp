#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	ifstream input("input.txt");

	double a;

	cout << fixed << setprecision(3);

	while (input >> a) {
		cout << a << endl;
	}

	//if (input.is_open()) {
	//	string value;
	//	cout << fixed << setprecision(3);
	//	while (getline(input, value)) {
	//		cout << stof(value) << endl;
	//	}
	//}
	return 0;
}
