#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

void swapPtr(int*& iptr1, int*& iptr2) {
	int* temp = iptr1;
	iptr1 = iptr2;
	iptr2 = temp;
}

int main()
{
	int i = 10, j = 20;
	int* iptr = &i, * jptr = &j;
	cout << "Before swap:\n" << "i = " << *iptr << ", j = " << *jptr << endl;
	cout << iptr << " " << jptr << endl;

	swapPtr(iptr, jptr);
	cout << "\nAfter swap:\n" << "i = " << *iptr << ", j = " << *jptr << endl;
	cout << iptr << " " << jptr << endl;
	return 0;
}