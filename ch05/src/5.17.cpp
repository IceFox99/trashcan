#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	vector<int> ivec1 = { 0, 1, 1, 2 };
	vector<int> ivec2 = { 0, 1, 1, 2, 3, 5, 8 };

	auto size = (ivec1.size() < ivec2.size()) ? ivec1.size() : ivec2.size();
	for (int i = 0; i != size; ++i) {
		if (ivec1[i] != ivec2[i]) {
			cout << "No!!" << endl;
			return -1;
		}
	}

	cout << "Yes!!" << endl;
	return 0;
}