#include <list>
#include <deque>
#include <iostream>

int main()
{
	std::list<int> li{0, 4, 2, 5, 3, 7, 11, -9, 3, 0}; // A random int list
	std::deque<int> evenDeque, oddDeque;
	for (const auto& i : li) {
		if (i % 2) // Odd
			oddDeque.push_back(i);
		else
			evenDeque.push_back(i);
	}

	// For testing
	std::cout << "Odd deque:";
	for (const auto& o : oddDeque)
		std::cout << " " << o;
	std::cout << std::endl << "Even deque:";
	for (const auto& e : evenDeque)
		std::cout << " " << e;
	std::cout << std::endl;

	return 0;
}