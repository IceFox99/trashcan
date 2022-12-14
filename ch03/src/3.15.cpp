#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
	string temp;
	vector<string> strings;
	cout << "Please input a string: ";
	while (cin >> temp) {
		strings.push_back(temp);
		cout << "Please input a string: ";
	}
	cout << "Your strings are ";
	for (auto s : strings)
		cout << s << " ";
	return 0;
}