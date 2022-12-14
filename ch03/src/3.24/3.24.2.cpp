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
	auto mid = beg + (end - beg) / 2;
	for (decltype(ivec.size()) i = 0; i != ivec.size() / 2; ++i) {
		cout << *beg + *(end - 1) << " ";
		beg += 1;
		end -= 1;
	}
	if (ivec.size() % 2 != 0)
		cout << *mid << " ";

	return 0;
}