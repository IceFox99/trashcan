#include <string>
#include <iostream>
#include "16.63.h"

int main()
{
	std::vector<double> dVec{ 0.5, 1.5, 2.0, 3.5, 3.14159, 2.0 };
	std::vector<int> iVec{ 0, 1, 1, 2, 3, 5, 8, 1, 1 };
	std::vector<std::string> sVec{ "cpp", "primer", "cpp", "fifth", "edition", "Cpp", "cpp" };
	std::cout << count(dVec, 2.0) << " " << count(iVec, 1) << " " << count(sVec, std::string("cpp")) << std::endl;
	return 0;
}