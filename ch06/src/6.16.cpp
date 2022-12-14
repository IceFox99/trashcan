#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

bool is_empty(const string& s) {
	return s.empty();
}

int main()
{
	string s = "Hello Motherfucker";
	cout << is_empty("") << endl;
	cout << is_empty(s) << endl;
	return 0;
}