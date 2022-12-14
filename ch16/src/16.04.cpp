#include <string>
#include <vector>
#include <list>
#include <iostream>

namespace ch16
{
	template <typename InputIt, typename T>
	InputIt find(InputIt first, InputIt last, const T& value)
	{
		for (; first != last; ++first) {
			if (*first == value)
				return first;
		}
		return last;
	}
}

int main()
{
	std::vector<int> vec{ 0, 1, 1, 2, 3, 5, 8, 13 };
	std::list<std::string> lst{ "first", "second", "third", "fourth" };
	std::cout << *ch16::find(vec.begin(), vec.end(), 5) << std::endl;
	std::cout << *ch16::find(lst.begin(), lst.end(), "second") << std::endl;
	return 0;
}