#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

void printVector(vector<int>::iterator iter, vector<int>::iterator end) {
	if (iter == end)
		return;
	cout << *iter << " ";
	return printVector(iter + 1, end);
}

int main()
{
	vector<int> ivec = { 1, 1, 2, 3, 5, 8 };
	printVector(ivec.begin(), ivec.end());
	return 0;
}