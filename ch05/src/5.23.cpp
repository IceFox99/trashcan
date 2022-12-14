#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int i1, i2;
	cout << "Please input two integers: ";
	cin >> i1 >> i2;
	cout << i1 << " / " << i2 << " = " << i1 / i2 << endl;
	return 0;
}