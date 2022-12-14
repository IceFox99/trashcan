#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end; using std::initializer_list;

int getSum(initializer_list<int> lst) {
	int sum = 0;
	for (auto i : lst)
		sum += i;
	return sum;
}

int main()
{
	cout << getSum({ 1, 3, 4, 7, 11 }) << endl;
	return 0;
}