#include <vector>
#include <list>
#include <iostream>

int main()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	std::vector<int> intVec(ia, std::end(ia));
	std::list<int> intList(ia, std::end(ia));

	// Remove even value
	for (auto intVecIter = intVec.begin(); intVecIter != intVec.end(); ) {
		if (*intVecIter % 2)
			++intVecIter;
		else
			intVecIter = intVec.erase(intVecIter);
	}

	// Remove odd value
	for (auto intListIter = intList.begin(); intListIter != intList.end(); ) {
		if (*intListIter % 2)
			intListIter = intList.erase(intListIter);
		else
			++intListIter;
	}

	// For testing
	std::cout << "Vector:";
	for (const auto& v : intVec)
		std::cout << " " << v;
	std::cout << std::endl << "List:";
	for (const auto& l :intList)
		std::cout << " " << l;
	std::cout << std::endl;

	return 0;
}