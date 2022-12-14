#include <map>
#include <iostream>

int main()
{
	std::map<int, std::string> m;
	m[10] = "test1";
	std::cout << "Before changing: " << m.cbegin()->first << " " << m.cbegin()->second << std::endl;

	auto iter = m.begin();
	iter->second = "test2";
	std::cout << "After changing: " << m.cbegin()->first << " " << m.cbegin()->second << std::endl;
	return 0;
}