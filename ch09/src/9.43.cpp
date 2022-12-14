#include <string>
#include <iostream>

void replaceStr(std::string& s, const std::string& oldVal, const std::string& newVal) {
	const auto oldSize = oldVal.size(), newSize = newVal.size();
	if (s.size() < oldSize)
		return;

	for (auto iter = s.begin(); iter <= s.end() - oldSize; ) {
		if (oldVal == std::string(iter, iter + oldSize)) {
			iter = s.erase(iter, iter + oldSize);
			iter = s.insert(iter, newVal.cbegin(), newVal.cend());
			iter += newSize;
		}
		else
			++iter;
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