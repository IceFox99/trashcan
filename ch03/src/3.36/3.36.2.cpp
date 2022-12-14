#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	vector<int> ivec1{ 10, 20, 30 };
	vector<int> ivec2{ 10, 25, 30 };

	if (ivec1.size() != ivec2.size()) {
		cout << "Not equal!" << endl;
		return -1;
	}
	else {
		auto ivec1_temp = ivec1.cbegin(), ivec2_temp = ivec2.cbegin();
		while ((ivec1_temp != ivec1.cend()) && (ivec2_temp != ivec2.cend())) {
			if (*ivec1_temp != *ivec2_temp) {
				cout << "Not equal!" << endl;
				return -1;
			}
			++ivec1_temp;
			++ivec2_temp;
		}
		cout << "Equal!" << endl;
		return 1;
	}
}