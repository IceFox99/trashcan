#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

void print(const int* beg, const std::size_t size) {
	for (std::size_t i = 0; i != size; ++i)
		cout << *beg++ << " ";
	cout << endl;
}

int main()
{
	int arr[100] = {};
	for (int i = 0; i != 100; ++i)
		arr[i] = i;

	print(arr, end(arr) - begin(arr));
	return 0;
}