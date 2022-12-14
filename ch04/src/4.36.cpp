#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int i = 10;
	double d = 13.7;
	i *= static_cast<int>(d);

	cout << i << endl;
	return 0;
}