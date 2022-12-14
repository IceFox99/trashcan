#include <forward_list>
#include <iostream>

int main()
{
	std::forward_list<int> intFList{0, 1, 1, 2, 3, 5, 8};
	auto prev = intFList.before_begin();
	auto curr = intFList.begin();
	while (curr != intFList.end()) {
		if (*curr % 2) // Remove odd-valued elements
			curr = intFList.erase_after(prev);
		else {
			prev = curr;
			++curr;
		}
	}

	// For testing
	for (const auto& i : intFList)
		std::cout << i << " ";

	return 0;
}