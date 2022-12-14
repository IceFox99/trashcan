#include "13.44.h"
#include <iostream>

int main()
{
	// Test constructor
	String s1("Test");
	std::cout << s1.c_str() << std::endl;

	// Test copy constructor
	String s2(s1);
	s2.push_back('2');
	std::cout << s2.c_str() << std::endl;

	// Test copy operator
	String s3("WTF");
	s3 = s1;
	std::cout << s3.c_str() << std::endl;

	// Test resize and reserve
	String s4(s1);
	s4.resize(10, '4');
	std::cout << s4.c_str() << std::endl;
	s4.resize(3);
	std::cout << s4.c_str() << std::endl;

	return 0;
}