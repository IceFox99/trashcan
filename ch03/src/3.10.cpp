#include <iostream>
#include <string>
#include <cctype>
using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string input, output;
	cout << "Please input a string: ";
	while (getline(cin, input)) {
		output = "";
		for (decltype(input.size()) i = 0; i < input.size(); i++) {
			if (!ispunct(input[i]))
				output += input[i];
		}
		cout << "After: " << output << endl;
		cout << "Please input a string: ";
	}
	return 0;
}