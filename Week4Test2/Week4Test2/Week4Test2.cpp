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

int main()
{
	ReadAll("input.txt");
	return 0;
}
