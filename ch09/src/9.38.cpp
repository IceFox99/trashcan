#include <vector>
#include <iostream>

void printSizeAndCapacity(const std::vector<int>& vec, const std::string& name = "vec") {
	std::cout << name << ": size:" << vec.size() << " capacity:" << vec.capacity() << std::endl;
}

int main()
{
	std::vector<int> v1;
	printSizeAndCapacity(v1, "v1");

	std::vector<int> v2(5);
	printSizeAndCapacity(v2, "v2");

	std::vector<int> v3;
	for (int i = 0; i != 10; ++i) {
		v3.push_back(i);
		printSizeAndCapacity(v3, "v3");
	}
	v3.shrink_to_fit();
	printSizeAndCapacity(v3, "v3");

	return 0;
}

// The output is
// v1: size:0 capacity:0
// v2: size:5 capacity:5
// v3: size:1 capacity:1
// v3: size:2 capacity:2
// v3: size:3 capacity:3
// v3: size:4 capacity:4
// v3: size:5 capacity:6
// v3: size:6 capacity:6
// v3: size:7 capacity:9
// v3: size:8 capacity:9
// v3: size:9 capacity:9
// v3: size:10 capacity:13
// v3: size:10 capacity:10