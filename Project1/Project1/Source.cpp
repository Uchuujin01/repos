#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Person {
	string name;
	string surname;
	int age;
};
 
int main() {
	vector<int> nums = { 1, 3, 5, 7 };
	cout << "Hello World!" << endl;
	cout << nums.size() << endl;

	map<string, int> n_to_v;
	n_to_v["one"] = 1;
	n_to_v["two"] = 2;
	cout << "two is " << n_to_v["two"];

	int x = 3;
	int y = 1;
	if ((x - y) * (x + y) > 10) {
		cout << "More than 10";
	}
	else {
		cout << "Less than 10";
	}

	vector<Person> staff;
	staff.push_back({ "ivan", "irsetskiy", 37 });
	staff.push_back({ "anton", "kuznetsov", 37 });

	cout << staff[0].name;

	system("pause");
	return 0;
}