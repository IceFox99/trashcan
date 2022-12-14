#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int temp;
	cout << "Please input an integer: ";
	while (cin >> temp) {
		if (temp == 42)
			break;
		else
			cout << "Please input an integer: ";
	}
	return 0;
}