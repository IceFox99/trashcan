#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end; using std::runtime_error;

int main()
{
	int i1, i2;
	cout << "Please input two integers: ";
	while (cin >> i1 >> i2) {
		try {
			if (i2 == 0)
				throw runtime_error("Division is 0!!");
			cout << i1 << " / " << i2 << " = " << i1 / i2 << endl;
			break;
		}
		catch (runtime_error err) {
			char c;
			cout << err.what() << endl;
			cout << "Do you wanna input again? Enter y or n: ";
			cin >> c;
			if (!c || c == 'n')
				break;
			else
				cout << "Please input two integers: ";
		}
	}

	return 0;
}