#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

class Date {
public:
	Date() {
		SetYear(0);
		SetMonth(0);
		SetDay(0);
	}
	Date(vector<string> v) {
		SetYear(v[0]);
		SetMonth(v[1]);
		SetDay(v[2]);
	}
	int GetYear() const {
		return year;
	};
	int GetMonth() const {
		return month;
	};
	int GetDay() const {
		return day;
	};
	void SetYear(int year_new) {
		year = year_new;
	};
	void SetMonth(int month_new) {
		month = month_new;
	};
	void SetDay(int day_new) {
		day = day_new;
	};
	void SetYear(string year_new) {
		year = stoi(year_new);
	};
	void SetMonth(string month_new) {
		month = stoi(month_new);
	};
	void SetDay(string day_new) {
		day = stoi(day_new);
	};
	void SetYear(istream& stream) {
		stream >> year;
	};
	void SetMonth(istream& stream) {
		stream >> month;
	};
	void SetDay(istream& stream) {
		stream >> day;
	};
	void SetDate(vector<string> v) {
		SetYear(v[0]);
		SetMonth(v[1]);
		SetDay(v[2]);
	};
	bool isValidMonth() {
		if ((month < 1) || (month > 12)) {
			return false;
		}
		else {
			return true;
		}
	};
	bool isValidDay() {
		if ((day < 1) || (day > 31)) {
			return false;
		}
		else {
			return true;
		}
	};
private:
	int year;
	int month;
	int day;
};

ostream& operator<<(ostream& stream, const Date& date) {

	stream << setfill('0') << setw(4) << date.GetYear() << '-' << setw(2) << date.GetMonth() << '-' << setw(2) << date.GetDay();
	return stream;
}

istream& operator>>(istream& stream, Date& date) {
	date.SetYear(stream);
	stream.ignore(1);
	date.SetMonth(stream);
	stream.ignore(1);
	date.SetDay(stream);
	return stream;
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() != rhs.GetYear()) {
		return lhs.GetYear() < rhs.GetYear();
	}
	else if (lhs.GetMonth() != rhs.GetMonth()) {
		return lhs.GetMonth() < rhs.GetMonth();
	}
	else {
		return lhs.GetDay() < rhs.GetDay();
	}
}

bool operator==(const Date& lhs, const Date& rhs) {
	return (lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() == rhs.GetMonth()) && (lhs.GetDay() == rhs.GetDay());
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		vector<string> events;
		if (count(database[date].begin(), database[date].end(), event) == 0) {
			database[date].push_back(event);
		}
	};
	bool DeleteEvent(const Date& date, const string& event) {
		if (database.count(date) > 0) {
			for (int i = 0; i < database[date].size(); ++i) {
				if (database[date][i] == event) {
					database[date].erase(database[date].begin() + i);
					if (database[date].size() == 0) {
						DeleteDate(date);
					}
					return true;
				}
			}	
			return false;
		}
		else {
			return false;
		}
	};
	int  DeleteDate(const Date& date) {
		map<Date, vector <string>>::iterator it = database.find(date);
		if (it != database.end()) {
			int val = database[date].size();
			database.erase(it);
			return val;
		}
		else {
			return 0;
		}
	};

	void Find(const Date& date) {
		if (database.count(date) > 0) {
			sort(database.at(date).begin(), database.at(date).end());
			for (auto s : database.at(date)) {
				cout << s << endl;
			}
		}
	};
  
	void Print() const {
		for (auto d : database) {
			sort(d.second.begin(), d.second.end());
			for (auto s : d.second) {
				cout << d.first << " " << s << endl;
			}
		}
	};
private:
	map<Date, vector<string>> database;
};

vector<string> CommandParse(string& str) {
	vector<string> stringOut;
	string s;
	s.erase();
	string::iterator it = str.begin();

	if (str.size() > 0) {
		do {
			if (*it != ' ') {
				s += *it;
			}
			else {
				if (s.size() > 0) {
					stringOut.push_back(s);
					s.erase();
				}
			}
			++it;
		} while (it != str.end());
		stringOut.push_back(s);
		return stringOut;
	}
	else {
		stringOut.push_back("empty");
		return stringOut;
	}
}

vector<string> DateParse(string& str) {
	vector<string> stringOut;
	string s;
	int delimiterCount = 0;
	s.erase();
	string::iterator it = str.begin();
	int minus = 0;

		do {
			if (*it != '-') {
				s += *it;
			}
			else {
				if (s.size() > 0) {
					delimiterCount++;
					minus = 0;
					stringOut.push_back(s);
					s.erase();
				}
				else {
					minus++;
					s += *it;
					if (minus > 1) {
						throw invalid_argument(str);
					}
				}
			}
			++it;
		} while (it != str.end());
		stringOut.push_back(s);


		if ((stringOut.size() == 3) && (delimiterCount == 2)) {
			for (int j = 0; j < stringOut.size(); ++j) {
				for (int i = 0; i < stringOut[j].size(); ++i) {
					if (!((stringOut[j][i] < ':') && (stringOut[j][i] > '/'))) {
						if ((j == 0) && (i == 0)) {
							if (stringOut[j][i] != '-') {
								if (stringOut[j][i] != '+') {
									throw invalid_argument(str);
								}
							}
						}
						else {
							throw invalid_argument(str);
						}
					}
				}
			}
		}
		else {
				throw invalid_argument(str);
		}
		return stringOut;
}
int main() {
  Database db;
  string command;

  while (getline(cin, command)) {
	  vector<string> commandParsed;
	  commandParsed.clear();
	  commandParsed = CommandParse(command);
	  bool isError = false;

	  if (commandParsed[0] == "Add") {
		  vector<string> dateIn;
		  try {
			  dateIn = DateParse(commandParsed[1]);
		  } catch (exception& e) {
			  cout << "Wrong date format: " << e.what() << endl;
			  isError = true;
		  }
		  if (!isError) {
			  Date date(dateIn);
			  if (!date.isValidMonth()) {
				  cout << "Month value is invalid: " << date.GetMonth() << endl;
			  }
			  else if (!date.isValidDay()) {
				  cout << "Day value is invalid: " << date.GetDay() << endl;
			  }
			  else {
				  string event = commandParsed[2];
				  db.AddEvent(date, event);
			  }
		  }
	  }
	  else if (commandParsed[0] == "Del") {
		  Date date(DateParse(commandParsed[1]));
		  if (commandParsed.size() > 2) {
			  string event = commandParsed[2];
			  if (db.DeleteEvent(date, event)) {
				  cout << "Deleted successfully" << endl;
			  }
			  else {
				  cout << "Event not found" << endl;
			  }
		  }
		  else {
			  cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
		  }
	  }
	  else if (commandParsed[0] == "Find") {
		  Date date(DateParse(commandParsed[1]));	  
			  db.Find(date);
	  }
	  else if (commandParsed[0] == "Print") {
		  db.Print();
	  }
	  else if (commandParsed[0] == "empty") {

	  }
	  else {
		  cout << "Unknown command: " << commandParsed[0] << endl;
	  }
  }

  return 0;
}