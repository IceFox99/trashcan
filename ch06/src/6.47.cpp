#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;
// #define NDEBUG

void printVector(vector<int> ivec, unsigned index) {
	auto size = ivec.size();
	if (index == size)
		return;

	cout << ivec[index];
#ifndef NDEBUG
	cout << "	The size of this vector is " << size << endl;
#endif // !NDEBUG
	return printVector(ivec, ++index);
}

int main()
{
	vector<int> ivec = { 1, 1, 2, 3, 5, 8 };
	printVector(ivec, 0);
	return 0;
}