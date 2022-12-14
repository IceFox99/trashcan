#include "13.44/13.44.h"
#include <vector>
#include <iostream>

int main()
{
	// CC for copy constructor, CA for copy assignment
	// MC for move constructor, MA for move assignment

	String s0("test");

	String s1(s0); // CC
	s1 = "test1"; // CA

	String s2 = s1; // CC
	s1.push_back('2');

	const char* temp = "test3";
	String s3(temp);

	String s4("test4");

	std::cout << "*********************" << std::endl;
	std::vector<String> strVec;
	// It will be CC * 2 for every push_back originally without move constructor and assignment, maybe because the copy is being made again when the vector is resized. (With move constructor and assignment)

	// When the vector is resized, MC will be called several times depends on the size.
	strVec.push_back(s1); // CC
	strVec.push_back(s2); // CC, MC
	strVec.push_back(s3); // CC, MC * 2
	strVec.push_back(s4); // CC, MC * 3
	std::cout << "Size: " << strVec.size() << std::endl;
	std::cout << "Capacity: " << strVec.capacity() << std::endl;

	return 0;
}