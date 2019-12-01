#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
	/* ��� ������������ ������������ ���� ���, ����������� ��������� ��������� ���� ������:
	   * ���������� ������� ���������� ��������
	   * ������ ���������� system_error
	   * ������ ������� ���������� � ����������.
	*/
	//throw system_error(error_code());
	throw domain_error("unknown problem");
	//return "00:00:11";
}

class TimeServer {
public:
	string GetCurrentTime() {
		/* ���������� ���� �����:
			* ���� AskTimeServer() ������� ��������, �������� ��� � last_fetched_time � �������
			* ���� AskTimeServer() ������� ���������� system_error, ������� ������� ��������
			���� last_fetched_time
			* ���� AskTimeServer() ������� ������ ����������, ���������� ��� ������.
		*/
		try {
			last_fetched_time = AskTimeServer();
			return last_fetched_time;
		}
		catch (system_error& e) {
			return last_fetched_time;
		}
	}

private:
	string last_fetched_time = "00:00:00";
};

int main() {
	// ����� ���������� ������� AskTimeServer, ���������, ��� ��� ��� �������� ���������
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	}
	catch (exception & e) {
		cout << "Exception got: " << e.what() << endl;
	}
	return 0;
}
