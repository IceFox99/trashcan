#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
	vector<string> strs;
	string temp;
	cout << "Please input a string: ";
	while (cin >> temp) {
		strs.push_back(temp);
		cout << "Please input a string: ";
	}

	for (auto& s : strs) {
		for (auto& c : s) {
			c = toupper(c);
		}
		cout << s << endl;
	}

	return 0;
}