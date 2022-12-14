#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

void print1(const int* beg, const int* end) {
	while (beg != end)
		cout << *beg++ << " ";
	cout << endl;
}

void print2(const int* beg, const std::size_t size) {
	for (std::size_t i = 0; i != size; ++i)
		cout << *beg++ << " ";
	cout << endl;
}

int main()
{
	int i = 0, j[2] = { 0, 1 };
	print1(&i, &i + 1);
	print1(begin(j), end(j));

	print2(&i, 1);
	print2(j, end(j) - begin(j));
	return 0;
}