#include <vector>
#include <iostream>

int main()
{
	std::vector<char> charVec{ 'S', 'H', 'I', 'T' };
	std::string str(charVec.cbegin(), charVec.cend());
	std::cout << str << std::endl;
	return 0;
}