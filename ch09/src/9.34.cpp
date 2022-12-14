#include <vector>
#include <iostream>

int main()
{
	std::vector<int> vi{ 0, 1, 1, 2, 3, 5, 8, 13};
	auto iter = vi.begin();
	while (iter != vi.end()) { // This loop will never end!
		if (*iter % 2) { // if the value is odd
			iter = vi.insert(iter, *iter); // Duplicate this value, but iterator points to inserted value
			++iter; // Add this line to fix the issue!!!!
		}
		++iter; // Now it points to original value, the iterator doesn't move forward.
	}

	// For testing
	for (const auto& i : vi)
		std::cout << i << " ";

	return 0;
}
