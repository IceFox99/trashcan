#include <vector>
#include <string>
#include <iostream>

int main()
{
	std::vector<std::string> intVec{ "3", "4", "-7", "0", "14" };
	std::vector<std::string> floatVec{ "3.14159", "-0.35", "132.342" };
	int intSum = 0;
	float floatSum = 0;
	for (const auto& i : intVec)
		intSum += std::stoi(i);
	for (const auto& f : floatVec)
		floatSum += std::stof(f);

	std::cout << "The sum of ints: " << intSum << std::endl;
	std::cout << "The sum of floats: " << floatSum << std::endl;
	return 0;
}