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
		
	/*
	if (ivec.size() % 2 == 0) {
		for (decltype(ivec.size()) i = 0; i < ivec.size(); i += 2) {
			cout << ivec[i] + ivec[i + 1] << " ";
		}
	}
	else {
		for (decltype(ivec.size()) i = 0; i < ivec.size() - 1; i += 2) {
			cout << ivec[i] + ivec[i + 1] << " ";
		}
		cout << ivec[ivec.size() - 1] << " ";
	}
	*/

	for (decltype(ivec.size()) i = 0; i < ivec.size() - 1; i += 2)
		cout << ivec[i] + ivec[i + 1] << " ";
	if (ivec.size() % 2 != 0)
		cout << ivec[ivec.size() - 1] << " ";
	return 0;
}