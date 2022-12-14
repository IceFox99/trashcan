#include <vector>
#include <iostream>

int main()
{
	std::vector<int> intVec{0, 1, 2, 3}, emptyIntVec;
	int v1 = intVec.at(0);
	int v2 = intVec[0];
	int v3 = intVec.front();
	int v4 = *intVec.begin();

	// For testing
	std::cout << "Using at: " << v1 << std::endl;
	std::cout << "Using subscript operator: " << v2 << std::endl;
	std::cout << "Using front: " << v3 << std::endl;
	std::cout << "Using begin: " << v4 << std::endl;

	// out_of_range exception
	/*int e1 = emptyIntVec.at(0);
	int e2 = emptyIntVec[0];
	int e3 = emptyIntVec.front();
	int e4 = *emptyIntVec.begin();

	std::cout << "Using at: " << e1 << std::endl;
	std::cout << "Using subscript operator: " << e2 << std::endl;
	std::cout << "Using front: " << e3 << std::endl;
	std::cout << "Using begin: " << e4 << std::endl;*/

	return 0;
}