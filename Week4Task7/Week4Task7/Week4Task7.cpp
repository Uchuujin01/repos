#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

struct Duration {
	int hour;
	int min;
	Duration(int h = 0, int m = 0) {
		int total = h * 60 + m;
		hour = h / 60;
		min = m % 60;
	}
};

ostream& operator<<(ostream& stream, const Duration& duration) {
	stream << setfill('0');
	stream << setw(2) << duration.hour << ':'
		<< setw(2) << duration.min;
	return stream;
}

istream& operator>>(istream& stream, Duration& duration) {
	stream >> duration.hour;
	stream.ignore(1);
	stream >> duration.min;
	return stream;
}

Duration operator+(const Duration& lhs, const Duration& rhs) {
	return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

bool operator<(const Duration& lhs, const Duration& rhs) {
	if (lhs.hour == rhs.hour) {
		return lhs.min < rhs.min;
	}
	return lhs.hour < rhs.hour;
}

int main()
{
	stringstream dur_ss("01:50");
	Duration dur1;
	dur_ss >> dur1;
	cout << dur1 << endl;
	return 0;
}
