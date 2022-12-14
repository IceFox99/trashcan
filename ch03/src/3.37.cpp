#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	const char ca[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
	const char* cp = ca;
	while (*cp) {
		cout << *cp << endl;
		++cp;
	}
	return 0;
}