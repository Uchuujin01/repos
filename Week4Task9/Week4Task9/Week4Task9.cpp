#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

void EnsureNextSym(stringstream& stream) {
	if (stream.peek() != '/') {
		stringstream ss;
		ss << "expected / , but has: " << char(stream.peek());
		throw runtime_error(ss.str());
	}
	stream.ignore(1);
}

Date ParseDate(const string& s) {
	stringstream stream(s);
	Date date;
	stream >> date.year;
	EnsureNextSym(stream);
	stream >> date.month;
	EnsureNextSym(stream);
	stream >> date.year;
	return date;
}

int main()
{
	string date_str = "2019a11f01";
	try {
		Date date = ParseDate(date_str);
		cout << setw(2) << setfill('0') << date.day << '.'
			<< setw(2) << setfill('0') << date.month << '.'
			<< date.year << endl;
	}
	catch (exception & ex) {
		cout << "exception happened: " << ex.what();
	}
	return(0);
}
