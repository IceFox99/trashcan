#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int fact(int num) {
	int result = 1;
	for (int i = num; i != 1; --i)
		result *= i;
	return result;
}

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