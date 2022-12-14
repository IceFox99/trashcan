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
	cin >> i1 >> i2;
	if (i2 == 0)
		throw runtime_error("Divisor is 0!!");
	cout << i1 << " / " << i2 << " = " << i1 / i2 << endl;
	return 0;
}