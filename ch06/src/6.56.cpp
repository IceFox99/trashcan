#include <iostream>
#include <string>
#include <vector>
#include "6.54.h"
using std::cin; using std::cout; using std::endl;
using std::string; using std::vector; using std::begin; using std::end;

int compute(int i, int j, int (*p)(int, int)) {
	return (*p)(i, j);
}

int main()
{
	typedef decltype(func)* Func;
	Func fa = &funcAdd;
	Func fs = &funcSubtract;
	Func fm = &funcMultiply;
	Func fd = &funcDivide;

	/*fvec.push_back(fa); // My stupid answer
	fvec.push_back(fs);
	fvec.push_back(fm);
	fvec.push_back(fd);

	for (auto fPtr : fvec) {
		cout << (*fPtr)(15, 3) << endl;
	}*/

	int i = 15, j = 3;
	fvec = { fa, fs, fm, fd };
	for (auto fPtr : fvec) {
		cout << compute(i, j, fPtr) << endl;
	}
	return 0;
}