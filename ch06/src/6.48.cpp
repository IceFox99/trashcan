#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;

int main()
{
	string s;
	while (cin >> s && s != "shit") {}
	assert(cin);
	return 0;
}