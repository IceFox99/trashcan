#include <iostream>
#include <string>

void replaceStr(std::string& s, const std::string& oldVal, const std::string& newVal) {
	const auto oldSize = oldVal.size(), newSize = newVal.size();
	if (s.size() < oldSize)
		return;

	for (std::string::size_type index = 0; index <= s.size() - oldSize; ) {
		if (s[index] == oldVal[0] && s.substr(index, oldSize) == oldVal) {
			s.replace(index, oldSize, newVal);
			index += newSize;
		}
		else
			++index;
	}
}

// For testing
int main()
{
	std::string test1("3q 33q 3q shit3q 3q3q 3qq 3q3q3q3q");
	std::cout << "Before replace: " << test1 << std::endl;
	replaceStr(test1, "3q", "ThankYou");
	std::cout << "After replace: " << test1 << std::endl;

	std::string test2("thothruthothothru");
	std::cout << "Before replace: " << test2 << std::endl;
	replaceStr(test2, "tho", "though");
	std::cout << "After replace: " << test2 << std::endl;

	std::string test3("Hello World!!");
	std::cout << "Before replace: " << test3 << std::endl;
	replaceStr(test3, "3q", "ThankYou");
	std::cout << "After replace: " << test3 << std::endl;
	return 0;
}