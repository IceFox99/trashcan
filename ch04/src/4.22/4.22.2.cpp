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

	if (grade < 60)
		result = "fail";
	else if (grade < 75)
		result = "low pass";
	else if (grade < 90)
		result = "pass";
	else
		result = "high pass";

	cout << result << endl;
	return 0;
}