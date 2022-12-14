#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	string str1, str2;
	cout << "Please input two strings: ";
	cin >> str1 >> str2;
	do {
		if (str1.size() == str2.size())
			cout << str1 << " " << str2 << endl;
		else if (str1.size() < str2.size())
			cout << str1 << endl;
		else
			cout << str2 << endl;

		cout << "Please input two strings: ";
	} while (cin >> str1 >> str2);
	return 0;
}