#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	constexpr std::size_t array_size = 10;
	int ia[array_size];
	for (std::size_t i = 0; i < array_size; i++) {
		ia[i] = i;
	}
	cout << "Before change: ";
	for (auto val : ia) {
		cout << val << " ";
	}
	cout << endl;

	for (int* p = begin(ia); p != end(ia); p++) {
		*p = 0;
	}
	cout << "After change: ";
	for (auto val : ia) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}