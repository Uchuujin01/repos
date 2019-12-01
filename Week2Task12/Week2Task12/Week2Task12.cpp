// Week2Task11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main()
{
	unordered_map<string, vector<string>> buses;
	//vector<vector<string>> buses;
	map<string, vector<string>> stops;
	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		string query;
		cin >> query;

		if (query == "NEW_BUS") {
			string busNum;
			int stopCount;
			cin >> busNum;
			cin >> stopCount;
			vector<string> busStops(stopCount);
			for (int i = 0; i < stopCount; ++i) {
				cin >> busStops[i];
					stops[busStops[i]].push_back(busNum);
			}
			buses[busNum] = busStops;
		}
		else if (query == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			int stopCount = 0;
			if (stops.count(stop) > 0) {
				for (auto b : buses) {
					for (int i = 0; i < b.second.size(); ++i) {
						if (b.second[i] == stop) {
							cout << b.first << " ";
							stopCount++;
						}
					}
				}
				cout << endl;
			}
			else {
				cout << "No stop" << endl;
			}

		}
		else if (query == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			int busCount = 0;
			if (buses.count(bus) > 0) {
				for (int i = 0; i < buses[bus].size(); ++i) {
					cout << "Stop " << buses[bus][i] << ": ";
					for (auto s : stops) {
						if (buses[bus][i] == s.first) {
							for (int j = 0; j < s.second.size(); ++j) {
								if (s.second[j] != bus) {
									cout << s.second[j] << " ";
									busCount++;
								}
							}
						}
					}
					if (busCount == 0) {
						cout << "no interchange" << endl;
					}
					else {
						cout << endl;
					}
					busCount = 0;
				}
			}
			else {
				cout << "No bus" << endl;
			}
		} else if (query == "ALL_BUSES") {
			if (buses.size() > 0) {
				map<string, vector<string>> orderedBuses;
				
				for (auto b : orderedBuses) {
					orderedBuses[b.first] = b.second;
				}
				for (auto b : orderedBuses) {
					cout << "Bus " << b.first << ": ";
					for (int i = 0; i < b.second.size(); ++i) {
						cout << b.second[i] << " ";
					}
					cout << endl;
				}
			}
			else {
				cout << "No buses" << endl;
			}
		}
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
