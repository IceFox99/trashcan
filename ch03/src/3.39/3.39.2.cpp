#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	char str1[] = "C++";
	char str2[] = "c++";

	if (strcmp(str1, str2) == 0)
		cout << "Same!" << endl;
	else
		cout << "Not same!" << endl;
	return 0;
}