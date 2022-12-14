#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
	vector<unsigned> scores(11, 0);
	auto beg = scores.begin();
	unsigned grade;
	while (cin >> grade) {
		if (grade <= 100)
			++* (beg + grade / 10);
	}

	auto temp = scores.begin();
	while (temp != scores.end()) {
		cout << *temp << " ";
		++temp;
	}

	return 0;
}