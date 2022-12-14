#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	string str1 = "Hello Motherfucker";
	string str2 = "Hello Motherfucker";

	if (str1 == str2)
		cout << "Same!" << endl;
	else
		cout << "Not same!" << endl;
	return 0;
}