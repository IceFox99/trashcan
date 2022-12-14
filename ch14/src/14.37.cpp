#include <vector>
#include <algorithm>
#include <iostream>

class TestEqual {
public:
	TestEqual(int i) :
		value(i) {}
	bool operator()(int i)
	{
		return i == value;
	}
private:
	int value;
};

int main()
{
	std::vector<int> intVec{ 1, 1, 2, 3, 5, 8, 13, 21, 1, 1, 2, 3 };
	std::replace_if(intVec.begin(), intVec.end(), TestEqual(1), 10);
	for (auto i : intVec)
		std::cout << i << " ";
	return 0;
}