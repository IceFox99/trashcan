#include <iostream>
#include "16.64.h"

int main()
{
	std::vector<const char*> sVec{ "cpp", "primer", "cpp", "fifth", "edition", "Cpp", "cpp" };
	std::cout << count<const char*>(sVec, "cpp") << std::endl;
	return 0;
}
