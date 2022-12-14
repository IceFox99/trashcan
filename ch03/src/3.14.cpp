#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
	int temp;
	vector<int> numbers;
	cout << "Please input a number: ";
	while (cin >> temp) {
		numbers.push_back(temp);
		cout << "Please input a number: ";
	}

	cout << "Your numbers are ";
	for (auto num : numbers)
		cout << num << " ";
	return 0;
}