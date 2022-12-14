#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int grade;
	string result;
	cout << "Please input your grade: ";
	cin >> grade;

	result = (grade < 60) ? "fail"
		: (grade < 75) ? "low pass"
		: (grade < 90) ? "pass"
		: "high pass";
	cout << result << endl;
	return 0;
}