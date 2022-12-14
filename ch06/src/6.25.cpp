#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main(int argc, char* argv[])
{
	string str;
	for (int i = 0; i != argc; ++i)
		str += argv[i];
	cout << str << endl;
	return 0;
}