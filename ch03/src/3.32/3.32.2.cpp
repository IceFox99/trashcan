#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
	const int ivec_size = 10;
	vector<int> ivec;
	for (int i = 0; i < ivec_size; i++) {
		ivec.push_back(i);
	}

	const int ivec_size_copy = ivec.size();
	vector<int> ivec_copy;
	for (int i = 0; i < ivec_size_copy; i++) {
		ivec_copy.push_back(ivec[i]);
	}

	cout << "The copy vector: ";
	for (auto val : ivec_copy) {
		cout << val << " ";
	}
	return 0;
}