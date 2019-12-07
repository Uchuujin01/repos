/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    firstNameHistory[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    lastNameHistory[year] = last_name;
  }
  string GetFullName(int year) {
      string firstName = GetFirstName(year);
      string lastName = GetLastName(year);
      
      if ((firstName != "NONE") && (lastName != "NONE")) {
          return firstName + " " + lastName;
      } else if ((firstName != "NONE") && (lastName == "NONE")) {
          return firstName + " with unknown last name";
      } else if ((firstName == "NONE") && (lastName != "NONE")) {
          return lastName + " with unknown first name";
      }
    return "Incognito";
  }
private:

    string GetFirstName(int year) {
        if (firstNameHistory.empty()) {
            return "NONE";
        }
        map<int, string, less_equal<int>>::key_compare yearCompare = firstNameHistory.key_comp();
     for (auto m : firstNameHistory) {
         if (yearCompare(m.first, year)) {
             return m.second;
         }
     }
     return "NONE";
    }
    
    string GetLastName(int year) {
        if (lastNameHistory.empty()) {
            return "NONE";
        }
        map<int, string, less_equal<int>>::key_compare yearCompare = lastNameHistory.key_comp();
     for (auto m : lastNameHistory) {
         if (yearCompare(m.first, year)) {
             return m.second;
         }
     }
     return "NONE";
    }
  map<int, string, less_equal<int>> firstNameHistory;
  map<int, string, less_equal<int>> lastNameHistory;
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
