#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v{ 0, 1, 1, 2, 3, 5, 8 };
	auto begin = v.begin();
	while (begin != v.end()) {
		// do some processing

		++begin;
		//begin = v.insert(begin, 100); // Correct code
		v.insert(begin, 100); // Incorrect code
		++begin;
	}

	// For testing
	for (const auto& i : v)
		std::cout << i << " ";

	// The program will crash because the iterator is invalid after inserting or deleting.
	return 0;
}