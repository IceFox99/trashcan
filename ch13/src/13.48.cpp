#include "13.44/13.44.h"
#include <vector>
#include <iostream>

int main()
{
	// CC for copy constructor, CA for copy assignment

	String s0("test");

	String s1(s0); // CC
	s1 = "test1"; // CA

	String s2 = s1; // CC
	s1.push_back('2');

	const char* temp = "test3";
	String s3(temp);

	std::cout << "*********************" << std::endl;
	std::vector<String> strVec;
	strVec.reserve(3); // Otherwise if will be CC * 2 for every push_back, maybe because the copy is being made again when the vector is resized. (Without move constructor and assignment)
	strVec.push_back(s1); // CC
	strVec.push_back(s2); // CC
	strVec.push_back(s3); // CC
	std::cout << "Size: " << strVec.size() << std::endl;
	std::cout << "Capacity: " << strVec.capacity() << std::endl;

	return 0;
}