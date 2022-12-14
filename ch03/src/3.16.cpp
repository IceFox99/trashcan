#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
	vector<int> v1; vector<int> v2(10); vector<int> v3(10, 42); vector<int> v4{ 10 };
	vector<int> v5{ 10, 42 }; vector<string> v6{ 10 }; vector<string> v7{ 10, "hi" };

	cout << "v1 size: " << v1.size() << endl;
	cout << "v1 members: ";
	for (auto iv1 : v1)
		cout << iv1 << " ";
	cout << endl;

	cout << "v2 size: " << v2.size() << endl;
	cout << "v2 members: ";
	for (auto iv2 : v2)
		cout << iv2 << " ";
	cout << endl;

	cout << "v3 size: " << v3.size() << endl;
	cout << "v3 members: ";
	for (auto iv3 : v3)
		cout << iv3 << " ";
	cout << endl;

	cout << "v4 size: " << v4.size() << endl;
	cout << "v4 members: ";
	for (auto iv4 : v4)
		cout << iv4 << " ";
	cout << endl;

	cout << "v5 size: " << v5.size() << endl;
	cout << "v5 members: ";
	for (auto iv5 : v5)
		cout << iv5 << " ";
	cout << endl;

	cout << "v6 size: " << v6.size() << endl;
	cout << "v6 members: ";
	for (auto sv6 : v6)
		cout << sv6 << " ";
	cout << endl;

	cout << "v7 size: " << v7.size() << endl;
	cout << "v7 members: ";
	for (auto sv7 : v7)
		cout << sv7 << " ";
	cout << endl;

	return 0;
}