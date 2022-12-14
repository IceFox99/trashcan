#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int ia[] = { 0, 1, 2, 3, 4, 5 };
	vector<int> ivec(begin(ia), end(ia));

	for (auto i : ivec)
		cout << i << " ";
	return 0;
}