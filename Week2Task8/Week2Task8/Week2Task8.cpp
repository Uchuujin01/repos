// Week2Task8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int GetNum(string& str) {

		//cout << "NUMBER " << number << endl;
		return stoi(str);
}

int main()
{
	int n = 0;
	int worryCount = 0;
	string prevoiusCommand;
	cin >> n;
	vector<string> commands;
	vector<int> args;
	vector<bool> queue;
	for (int i = 0; i < n * 2; ++i) {
		string c;
		cin >> c;
		if ((prevoiusCommand == "COME") || (prevoiusCommand == "WORRY") || (prevoiusCommand == "QUIET")) {
			args.push_back(GetNum(c));
			prevoiusCommand = "";
		}
		else if (prevoiusCommand == "WORRY_COUNT") {
			args.push_back(0);
			prevoiusCommand = "";
		}
		if ((c == "COME") || (c == "WORRY") || (c == "QUIET") || (c == "WORRY_COUNT")) {
			commands.push_back(c);
			prevoiusCommand = c;
			if (c == "WORRY_COUNT") {
				i++;
			}
		}
	}

	for (int i = 0; i < commands.size(); ++i) {
			if (commands[i] == "COME") {
				if ((args[i] != 0) && ((queue.size() + args[i]) >= 0)) {
				
					queue.resize(queue.size() + args[i]);

				}
				//cout << "COME " << args[i] <<endl;
			}
			else if (commands[i] == "WORRY") {
				if (/*(args[i] < queue.size()) && */!(args[i] < 0)) {
					queue.at(args[i]) = true;
				}
			}
			else if (commands[i] == "QUIET") {
				if (/*(args[i] < queue.size()) && */!(args[i] < 0)) {
					queue.at(args[i]) = false;
				}
			}
			else if (commands[i] == "WORRY_COUNT") {
				for (auto a : queue) {
					if (a) {
						worryCount++;
					}
				}
				cout << worryCount << endl;
				worryCount = 0;
			}
	}
	return 0;
}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	int q;
//	cin >> q;
//	vector<bool> is_nervous;
//
//	for (int i = 0; i < q; ++i) {
//		string operation_code;
//		cin >> operation_code;
//
//		if (operation_code == "WORRY_COUNT") {
//
//			// подсчитываем количество элементов в векторе is_nervous, равных true
//			cout << count(begin(is_nervous), end(is_nervous), true) << endl;
//
//		}
//		else {
//			if (operation_code == "WORRY" || operation_code == "QUIET") {
//
//				int person_index;
//				cin >> person_index;
//
//				// выражение в скобках имеет тип bool и равно true для запроса WORRY,
//				// поэтому is_nervous[person_index] станет равным false или true
//				// в зависимости от operation_code
//				is_nervous[person_index] = (operation_code == "WORRY");
//
//			}
//			else if (operation_code == "COME") {
//
//				int person_count;
//				cin >> person_count;
//
//				// метод resize может как уменьшать размер вектора, так и увеличивать,
//				// поэтому специально рассматривать случаи с положительным
//				// и отрицательным person_count не нужно
//				is_nervous.resize(is_nervous.size() + person_count, false);
//
//			}
//		}
//	}
//
//	return 0;
//}