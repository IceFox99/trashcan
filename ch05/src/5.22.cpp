#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	vector<int> ivec = { 0, 1, 2, 3, 4 };
	decltype(ivec.size()) sz;
	do {
		sz = ivec.size();
	} while (sz <= 0);

	return 0;
}