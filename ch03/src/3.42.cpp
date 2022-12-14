#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	const int size = 10;
	vector<int> ivec;
	for (int i = 0; i != size; i++) {
		ivec.push_back(i);
	}

	int ia[size];
	auto it = ivec.begin();
	for (auto& i : ia) {
		i = *it;
		++it;
	}

	for (auto i : ia) {
		cout << i << " ";
	}

	return 0;
}