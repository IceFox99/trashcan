#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
	vector<int> numbers(10, 5);
	cout << "Before change: ";
	for (auto it = numbers.cbegin(); it != numbers.cend(); ++it)
		cout << *it << " ";
	cout << endl;

	for (auto it = numbers.begin(); it != numbers.end(); ++it)
		(*it) *= 2;

	cout << "After change: ";
	for (auto it = numbers.cbegin(); it != numbers.end(); ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}