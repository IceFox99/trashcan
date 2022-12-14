#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int ia[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};

	for (auto i = 0; i < 3; ++i) {
		for (auto j = 0; j < 4; ++j)
			cout << ia[i][j] << " ";
		cout << endl;
	}
	return 0;
}