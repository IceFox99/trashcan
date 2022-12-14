#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int getLarger(const int i, const int* iptr) {
	return (i > *iptr) ? i : *iptr;
}

int main()
{
	int i = 100, j = 105;
	int* jptr = &j;
	cout << getLarger(i, jptr) << endl;;

	return 0;
}