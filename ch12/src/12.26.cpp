#include <memory>
#include <string>
#include <iostream>

int main()
{
	int n = 10;

	// Original
	/*std::string* const p = new std::string[n];
	std::string s;
	std::string* q = p;
	while (std::cin >> s && q != p + n)
		*q++ = s;
	const std::size_t size = q - p;
	for (auto temp = p; temp != q; ++temp)
		std::cout << *temp << std::endl;
	delete [] p;*/

	// New
	std::allocator<std::string> all;
	auto const ptr = all.allocate(n);
	std::string tempStr;
	auto tempPtr = ptr;
	while (tempPtr != ptr + n && std::cin >> tempStr)
		all.construct(tempPtr++, tempStr);

	for (auto temp = ptr; temp != tempPtr; ++temp)
		std::cout << *temp << std::endl;

	while (tempPtr != ptr)
		all.destroy(--tempPtr);
	all.deallocate(ptr, n);
	return 0;
}