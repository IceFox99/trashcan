#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> intVec;
	std::istream_iterator<int> int_iter(std::cin), eof;
	std::ostream_iterator<int> output(std::cout, " ");
	while (int_iter != eof)
		intVec.push_back(*int_iter++);
	std::sort(intVec.begin(), intVec.end());
	for (const auto& i : intVec)
		output = i;
	return 0;
}