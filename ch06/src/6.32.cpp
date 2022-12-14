#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int& get(int* arr, int index) {
	return arr[index];
}

int main()
{
	int ia[10];
	for (int i = 0; i != 10; ++i) {
		get(ia, i) = i;
	}

	for (auto i : ia)
		cout << i << " ";
	cout << endl;
	return 0;
}