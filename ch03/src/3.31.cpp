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

	cout << "This array: ";
	for (auto val : ia) {
		cout << val << " ";
	}

	return 0;
}