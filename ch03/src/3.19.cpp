#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
	vector<int> ivec1(10, 42);
	vector<int> ivec2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
	vector<int> ivec3(10);
	vector<int> ivec4;

	// Initialization
	for (auto& i : ivec3)
		i = 42;
	for (int i = 0; i < 10; i++)
		ivec4.push_back(42);

	cout << "ivec1: ";
	for (auto& i : ivec1)
		cout << i << " ";
	cout << endl;

	cout << "ivec2: ";
	for (auto& i : ivec2)
		cout << i << " ";
	cout << endl;

	cout << "ivec3: ";
	for (auto& i : ivec3)
		cout << i << " ";
	cout << endl;

	cout << "ivec4: ";
	for (auto& i : ivec4)
		cout << i << " ";
	cout << endl;

	return 0;
}