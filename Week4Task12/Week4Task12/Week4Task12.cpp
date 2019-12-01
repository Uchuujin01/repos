#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <exception>
using namespace std;

class Rational {
public:
	Rational(int numerator_in = 0, int denominator_in = 1) {
		int comm_div = CommonDivider(numerator_in, denominator_in);
		numerator = numerator_in / comm_div;
		denominator = denominator_in / comm_div;
		SignCheck();
	}

	int Numerator() const {
		return numerator;
	}

	int Denominator() const {
		return denominator;
	}

	void SetNumerator(istream& stream) {
		stream >> numerator;
	}

	void SetDenominator(istream& stream) {
		stream >> denominator;
	}

	void CommonDividerCheck() {
		int comm_div = CommonDivider(numerator, denominator);
		numerator = numerator / comm_div;
		denominator = denominator / comm_div;
	}

	void SignCheck() {
		if ((numerator > 0) && (denominator < 0)) {
			numerator *= -1;
			denominator *= -1;
		}
		else if ((numerator < 0) && (denominator < 0)) {
			denominator *= -1;
			numerator *= -1;
		}
		else if (numerator == 0) {
			denominator = 1;
		}
	}

private:
	int numerator;
	int denominator;

	int CommonDivider(int a, int b) {
		a = abs(a);
		b = abs(b);
		if (b == 0) {
			throw invalid_argument("Invalid argument");
		}
		while (a > 0 && b > 0) {

			if (a > b) {
				a %= b;
			}
			else {
				b %= a;
			}
		}
		return a + b;
	}
};

ostream& operator<<(ostream& stream, const Rational& rational) {
	stream << rational.Numerator() << '/' << rational.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
	rational.SetNumerator(stream);
	stream.ignore(1);
	rational.SetDenominator(stream);
	rational.CommonDividerCheck();
	rational.SignCheck();
	return stream;
}

Rational operator*(const Rational& first, const Rational& second) {
	int result_denom = first.Denominator() * second.Denominator();
	int result_num = first.Numerator() * second.Numerator();
	return Rational(result_num, result_denom);
}

Rational operator+(const Rational& first, const Rational& second) {
	int result_denom = first.Denominator() * second.Denominator();
	int result_num = first.Numerator() * second.Denominator() + second.Numerator() * first.Denominator();
	return Rational(result_num, result_denom);
}

Rational operator-(const Rational& first, const Rational& second) {
	int result_denom = first.Denominator() * second.Denominator();
	int result_num = first.Numerator() * second.Denominator() - second.Numerator() * first.Denominator();
	return Rational(result_num, result_denom);
}

bool operator==(const Rational& first, const Rational& second) {
	if (first.Numerator() == second.Numerator() && first.Denominator() == second.Denominator()) {
		return true;
	}
	else {
		return false;
	}
}

Rational operator/(const Rational& first, const Rational& second) {
	if (second == Rational{ 0,1 }) {
		throw domain_error("Division by zero");
	}
	int result_denom = first.Denominator() * second.Numerator();
	int result_num = first.Numerator() * second.Denominator();
	return Rational(result_num, result_denom);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
	return (lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator());
}

Rational Operation(istream& input) {
	Rational first, second;
	char op;
	input >> first;
	input.ignore(1);
	input >> op;
	input.ignore(1);
	input >> second;
	if (op == '+') {
		return first + second;
	}
	else if (op == '-') {
		return first - second;
	}
	else if (op == '*') {
		return first * second;
	}
	else if (op == '/') {
		return first / second;
	}
}

int main() {

	try {
		cout << Operation(cin);
	}
	catch (exception & ex) {
		cout <<ex.what();
	}
	return 0;
}
