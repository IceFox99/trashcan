#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

void reset(int& i) {
	i = 0;
}

int main()
{
	int test = 100;
	cout << "Before change: " << test << endl;

	reset(test);
	cout << "After change: " << test << endl;
	return 0;
}