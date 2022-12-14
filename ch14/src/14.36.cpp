#include "14.35.h"
#include <vector>

int main()
{
	ReadString rs;
	std::vector<std::string> strVec;
	std::string temp;
	while ((temp = rs()) != "")
		strVec.push_back(temp);
	std::cout << "*****************" << std::endl;
	for (auto str : strVec)
		std::cout << str << std::endl;
	return 0;
}