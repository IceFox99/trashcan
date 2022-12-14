#include <iostream>
#include <string>
#include <vector>
#include "../6.54.h"
using std::cin; using std::cout; using std::endl;
using std::string; using std::vector; using std::begin; using std::end;

int main()
{
	typedef decltype(func)* Func;
	Func fa = &funcAdd;
	Func fs = &funcSubtract;
	Func fm = &funcMultiply;
	Func fd = &funcDivide;

	fvec.push_back(fa);
	fvec.push_back(fs);
	fvec.push_back(fm);
	fvec.push_back(fd);

	return 0;
}