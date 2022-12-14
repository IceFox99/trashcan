#include <iterator>
#include <iostream>
#include <vector>
#include <list>

int main()
{
	auto printVec = [](const std::list<int>& iVec) {
		for (const auto& i : iVec)
			std::cout << i << " ";
		std::cout << std::endl;
	};

	std::vector<int> iVec { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::list<int> v1, v2, v3;
	std::copy(iVec.cbegin(), iVec.cend(), inserter(v1, v1.begin()));
	std::copy(iVec.cbegin(), iVec.cend(), back_inserter(v2));
	std::copy(iVec.cbegin(), iVec.cend(), front_inserter(v3));

	std::cout << "Using inserter: ";
	printVec(v1);

	std::cout << "Using back_inserter: ";
	printVec(v2);

	std::cout << "Using fron_inserter: ";
	printVec(v3);
	return 0;
}