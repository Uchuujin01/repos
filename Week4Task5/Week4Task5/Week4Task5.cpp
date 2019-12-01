#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	ifstream input("input.txt");
	int n, m;
	input >> n;
	input.ignore(1);
	input >> m;
	// input >> n >> m;
	for (int i = 0; i < n; ++i) {
		
		for (int j = 0; j < m; ++j) {
			int value;
			input >> value;
			input.ignore(1);
			cout << setw(10) << value;
			if (j != m - 1) {
				cout << ' ';
			}
		}
		if (i != n - 1) {
			cout << endl;
		}
	}
	return 0;
}
