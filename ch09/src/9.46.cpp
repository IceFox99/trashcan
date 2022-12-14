#include <string>
#include <iostream>

std::string genName(const std::string& name, const std::string& prefix = "", const std::string& suffix = "") {
	std::string fullName(name);
	if (!prefix.empty())
		fullName.insert(0, prefix + " ");
	if (!suffix.empty())
		fullName.insert(fullName.size(), " " + suffix);

	return fullName;
}

// For testing
int main()
{
	std::cout << genName("Hu", "Mr.", "Jr.") << std::endl;
	std::cout << genName("Yuefeng Hu") << std::endl;
	std::cout << genName("Hu", "Mr.") << std::endl;
	return 0;
}