#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	// My Stupid Answer
/*	string cStr, nStr, finalStr;
	cout << "Please input a string: ";
	if (!(cin >> cStr))
		return -1;

	cout << "Please input a string: ";
	while (cin >> nStr) {
		if (nStr == cStr) {
			cout << "The duplicated string is " << "\"" << nStr << "\"." << endl;
			finalStr = nStr;
			break;
		}
		finalStr = cStr;
		cStr = nStr;
		cout << "Please input a string: ";
	}
	if (cStr != finalStr)
		cout << "No duplicated string!" << endl;	*/

		// Efficient Answer
	string pastStr, currentStr;
	bool repeat = false;
	cout << "Please input a string: ";
	while (cin >> currentStr) {
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