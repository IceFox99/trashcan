#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	vector<int> ivec = { 1, 3, 4, 5, 8, 11 };

	for (auto& val : ivec)
		val = (val % 2 == 1) ? val * 2 : val;

	for (auto it : ivec)
		cout << it << " ";
	return 0;
}