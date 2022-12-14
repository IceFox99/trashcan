#include <algorithm>
#include <iostream>
#include <list>
#include <iterator>

int main()
{
	std::list<int> iLst{ 0, 1, 1, 3, 0, 5, 0 };
	auto lastZero = std::find(iLst.crbegin(), iLst.crend(), 0);
	std::cout << "The last 0 is at index " << std::distance(lastZero, iLst.crend()) - 1 << "." << std::endl;
	return 0;
}1