#include <iostream>
#include <string>
#include <vector>
#include "Chapter6.h"
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int temp;
	cout << "Please input an integer: ";
	while (cin >> temp) {
		cout << "The factorail of " << temp << " is " << fact(temp) << "." << endl;
		cout << "Please input an integer: ";
	}
	return 0;
}