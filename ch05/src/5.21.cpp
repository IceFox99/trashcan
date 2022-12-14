#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	string pastStr, currentStr;
	bool repeat = false;
	cout << "Please input a string: ";
	while (cin >> currentStr) {
		if (!isupper(currentStr[0])) {
			pastStr = currentStr;
			cout << "Please input a string: ";
			continue;
		}

		if (currentStr == pastStr) {
			repeat = true;
			cout << "The duplicated string is " << "\"" << currentStr << "\"." << endl;
			break;
		}
		pastStr = currentStr;
		cout << "Please input a string: ";
	}
	if (!repeat)
		cout << "No duplicated string!" << endl;
	return 0;
}