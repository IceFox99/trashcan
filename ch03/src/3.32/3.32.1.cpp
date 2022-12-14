#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
	constexpr std::size_t array_size = 10;
	int ia[array_size];
	for (std::size_t i = 0; i < array_size; i++) {
		ia[i] = i;
	}

	constexpr std::size_t array_size_copy = sizeof(ia) / sizeof(ia[0]);
	int ia_copy[array_size_copy];
	for (std::size_t i = 0; i < array_size_copy; i++) {
		ia_copy[i] = ia[i];
	}

	cout << "The copy array: ";
	for (auto val : ia_copy) {
		cout << val << " ";
	}
	return 0;
}