#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string str1, str2;
	cout << "Please input first string: ";
	cin >> str1;
	cout << "Please input second string: ";
	cin >> str2;
	if (str1.size() == str2.size())
		cout << "Their length is the same!" << endl;
	else if (str1 > str2)
		cout << str1 << endl;
	else
		cout << str2 << endl;
	return 0;
}