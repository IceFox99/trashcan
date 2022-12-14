#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int ia1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ia2[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::size_t ia1_size = sizeof(ia1) / sizeof(ia1[0]);
	std::size_t ia2_size = sizeof(ia2) / sizeof(ia2[0]);
	if (ia1_size != ia2_size) {
		cout << "Not equal!" << endl;
		return -1;
	}
	else {
		for (std::size_t i = 0; i < ia1_size; i++) {
			if (ia1[i] != ia2[i]) {
				cout << "Not equal!" << endl;
				return -1;
			}
		}
		cout << "Equal!" << endl;
		return 1;
	}
}