#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int ia[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};

	for (int(*p)[4] = begin(ia); p != end(ia); ++p) {
		for (int* q = begin(*p); q != end(*p); ++q) {
			cout << *q << " ";
		}
		cout << endl;
	}
	return 0;
}