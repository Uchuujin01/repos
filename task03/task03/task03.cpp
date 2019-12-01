//#include "pch.h"
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	double a, b, c, d;
	double x1, x2;
	x1 = 0;
	x2 = 0;
	cin >> a >> b >> c;
	d = pow(b, 2) - 4 * a * c;
	if (a == 0) {
		x1 = -c / b;
		if (b != 0) {
			cout << x1;
		}
	return 0;
	}
	if (d > 0) {
		x1 = (-b + sqrt(d)) / (2.0 * a);
		x2 = (-b - sqrt(d)) / (2.0 * a);
		cout << x1 << " " << x2;
	}
	else if (d == 0) {
		x1 = -b / (2.0 * a);
		cout << x1;
	}
	return 0;
}
