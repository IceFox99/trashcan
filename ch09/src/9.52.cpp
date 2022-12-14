#include <stack>
#include <string>
#include <iostream>

int main()
{
	std::string str("This is (IceFox99)!");
	std::stack<char> s;
	bool parenthesis = false;

	for (const auto& c : str) {
		if (c == '(') {
			parenthesis = true;
			continue;
		}
		if (parenthesis && c != ')')
			s.push(c);
		else
			parenthesis = false;
	}
	std::string value;
	while (!s.empty()) {
		value.insert(value.cbegin(), s.top());
		s.pop();
	}

	str.replace(str.find("(") + 1, value.size(), value + " IS DETECTED");
	std::cout << str << std::endl;

	return 0;
}