#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> intVec, uniVec;
	std::istream_iterator<int> int_iter(std::cin), eof;
	std::ostream_iterator<int> output(std::cout, " ");
	while (int_iter != eof)
		intVec.push_back(*int_iter++);
	std::sort(intVec.begin(), intVec.end());
	std::unique_copy(intVec.begin(), intVec.end(), std::back_inserter(uniVec));
	for (const auto& i : uniVec)
		output = i;

	return 0;
}