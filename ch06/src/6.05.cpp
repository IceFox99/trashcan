#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

double absoluteValue(double input) {
	return (input >= 0) ? input : -input;
}

int main()
{
	double temp;
	cout << "Please input an integer: ";
	while (cin >> temp) {
		cout << "The absolute value of " << temp << " is " << absoluteValue(temp) << "." << endl;	// My method
		cout << "The absolute value of " << temp << " is " << abs(temp) << "." << endl;	// STD's method
		cout << "\nPlease input an integer: ";
	}
	return 0;
}