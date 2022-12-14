#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string temp;
	cout << "Please input a string: ";
	while (getline(cin, temp)) {
		cout << "Before changing: " << temp << endl;
		for (char& c : temp)
			c = 'X';
		cout << "After changing: " << temp << endl;
		cout << "Please input a string: ";
	}
	return 0;
}