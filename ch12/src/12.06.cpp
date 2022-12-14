#include <vector>
#include <iostream>

std::vector<int>* MakeIntVector() {
	return new std::vector<int>();
}

std::vector<int>* AssignVector(std::istream& is, std::vector<int>* ptr) {
	int temp;
	std::cout << "Please input an integer: ";
	while (is >> temp) {
		ptr->push_back(temp);
		std::cout << "Please input an integer: ";
	}
	return ptr;
}

void PrintVector(std::vector<int>* ptr) {
	std::cout << "The vector contains: " << std::endl;
	for (const auto& i : *ptr)
		std::cout << i << " ";
}

int main()
{
	auto ptr = AssignVector(std::cin, MakeIntVector());
	PrintVector(ptr);
	delete ptr;
	return 0;
}