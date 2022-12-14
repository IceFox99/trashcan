#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
	vector<int> ivec;
	int temp;
	cout << "Please input an integer: ";
	while (cin >> temp) {
		ivec.push_back(temp);
		cout << "Please input an integer: ";
	}

	auto beg = ivec.begin(), end = ivec.end();
	while (beg < end - 1) {
		cout << *beg + *(beg + 1) << " ";
		beg += 2;
	}
	if (ivec.size() % 2 != 0)
		cout << *(ivec.end() - 1);

	return 0;
}