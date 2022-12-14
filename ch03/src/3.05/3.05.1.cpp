#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string sum = "", temp;
	cout << "Please input first string: ";
	while (cin >> temp) {
		sum += temp;
		cout << "Please input next string: ";
	}
	cout << "Their sum is " << sum << endl;
	return 0;
}