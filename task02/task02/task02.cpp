#include "pch.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;
	vector<string> str = {str1, str2, str3};
	sort(str.begin(), str.end());
	cout << str[0];
	return 0;
}