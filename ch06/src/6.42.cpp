#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::string; using std::vector; using std::begin; using std::end;

string make_plural(std::size_t ctr, const string& word, const string& ending = "s") {
	return (ctr > 1) ? word + ending : word;
}

int main()
{
	cout << make_plural(1, "success") << endl;
	cout << make_plural(2, "success", "es") << endl;

	cout << make_plural(1, "failure") << endl;
	cout << make_plural(2, "failure") << endl;

	return 0;
}