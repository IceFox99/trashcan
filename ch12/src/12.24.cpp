#include <memory>
#include <string>
#include <iostream>

int main()
{
	char* str = new char[11]();
	std::cin.get(str, 11);
	std::cout << str << std::endl;

	delete [] str;
	return 0;
}