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

	for (decltype(ivec.size()) i = 0; i < ivec.size() / 2; i++)
		cout << ivec[i] + ivec[ivec.size() - 1 - i] << " ";
	if (ivec.size() % 2 != 0)
		cout << ivec[ivec.size() / 2];

	return 0;
}