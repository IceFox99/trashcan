#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> a{ 0, 1, 1, 2, 3, 5, 8, 1024, 1025, 1026, 9999, 10 };
	std::vector<std::string> b{ "pooh", "pooh", "shit", "fuck" };
	std::vector<int> c{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };

	const auto count = std::count_if(a.begin(), a.end(), std::bind(std::greater<int>(), std::placeholders::_1, 1024)); // Exercise a
	const auto iter = std::find_if(b.begin(), b.end(), std::bind(std::not_equal_to<std::string>(), std::placeholders::_1, "pooh")); // Exercise b
	std::transform(c.begin(), c.end(), c.begin(), std::bind(std::multiplies<int>(), std::placeholders::_1, 2));

	std::cout << "Exercise a: " << count << std::endl;
	std::cout << "Exercise b: " << *iter << std::endl;
	std::cout << "Exercise c: ";
	for (const auto& i : c)
		std::cout << i << " ";
	return 0;
}