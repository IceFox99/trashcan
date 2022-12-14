#include <vector>
#include <memory>
#include <iostream>

std::shared_ptr<std::vector<int>> MakeIntVector() {
	return std::make_shared<std::vector<int>>();
}

std::shared_ptr<std::vector<int>> AssignVector(std::istream& is, std::shared_ptr<std::vector<int>> ptr) {
	int temp;
	std::cout << "Please input an integer: ";
	while (is >> temp) {
		ptr->push_back(temp);
		std::cout << "Please input an integer: ";
	}
	return ptr;
}

void PrintVector(std::shared_ptr<std::vector<int>> ptr) {
	std::cout << "The vector contains: " << std::endl;
	for (const auto& i : *ptr)
		std::cout << i << " ";
}

int main()
{
	auto ptr = AssignVector(std::cin, MakeIntVector());
	PrintVector(ptr);
	return 0;
}