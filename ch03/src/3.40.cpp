#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	char str1[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	char str2[] = { 'M', 'o', 't', 'h', 'e', 'r', 'f', 'u', 'c', 'k', 'e', 'r', '\0' };
	char str3[100];

	strcpy_s(str3, str1);
	strcat_s(str3, " ");
	strcat_s(str3, str2);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	return 0;
}