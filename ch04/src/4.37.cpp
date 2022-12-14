#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	string s("shit");
	char c('s');
	int i; double d; const string* ps = &s; char* pc = &c; void* pv;

	pv = static_cast<void*>(const_cast<string*>(ps));		// (a)
	i = static_cast<int>(*pc);			// (b)
	pv = static_cast<void*>(&d);		// (c)
	pc = static_cast<char*>(pv);		// (d)

	return 0;
}