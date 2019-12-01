#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void ReadAll(const string& pathIn,const string& pathOut) {
	ifstream input(pathIn);
	ofstream output(pathOut);
	if (input.is_open()) {
		string line;
		while (getline(input, line)) {
			output << line << endl;
		}
	}
}

int main()
{
	ReadAll("input.txt", "output.txt");
	return 0;
}
