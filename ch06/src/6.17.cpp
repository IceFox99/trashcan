#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

bool haveCapitalLetter(const string& str) {
	for (auto c : str) {
		if (isupper(c))
			return true;
	}
	return false;
}

void toAllLowercase(string& str) {
	for (auto& c : str)
		c = tolower(c);
}

int main()
{
	string str1 = "hello motherfucker";
	string str2 = "Hello Motherfucker";
	cout << haveCapitalLetter(str1) << endl;				// 0
	cout << haveCapitalLetter(str2) << endl << endl;		// 1

	toAllLowercase(str2);
	cout << str2 << endl;									// hello motherfucker
	return 0;
}