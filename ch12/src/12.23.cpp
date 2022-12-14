#include <memory>
#include <string>
#include <iostream>

int main()
{
	char* str = new char[strlen("Hello" "World") + 1]();
	strcat_s(str, 11, "Hello"); // strcat(str, "Hello");
	strcat_s(str, 11, "World"); // strcat(str, "World");
	std::cout << str << std::endl;
	delete [] str;

	std::string str1 = "Hello", str2 = "World";
	std::cout << str1 + str2 << std::endl;

	return 0;
}