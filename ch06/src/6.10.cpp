#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

void exchangeInt(int* i1, int* i2) {
	int temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}

int main()
{
	int a = 5, b = 10;
	cout << "Before change:\n" << "a = " << a << ", b = " << b << endl;

	exchangeInt(&a, &b);
	cout << "After change:\n" << "a = " << a << ", b = " << b << endl;
	return 0;
}