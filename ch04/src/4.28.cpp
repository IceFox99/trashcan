#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	cout << "bool: " << sizeof(bool) << endl;
	cout << "char: " << sizeof(char) << endl;
	cout << "wchar_t: " << sizeof(wchar_t) << endl;
	cout << "char16_t: " << sizeof(char16_t) << endl;
	cout << "char32_t: " << sizeof(char32_t) << endl;
	cout << "short: " << sizeof(short) << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "long: " << sizeof(long) << endl;
	cout << "long long: " << sizeof(long long) << endl;
	cout << "float: " << sizeof(float) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "long double: " << sizeof(long double) << endl;
	return 0;
}