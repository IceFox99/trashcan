#include <list>
#include <forward_list>
#include <iostream>

int main()
{
	std::list<int> li = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::forward_list<int> fLi = { 0, 1, 1, 2, 3, 5, 8, 13, 21 };

	// list
	auto liIter = li.begin();
	while (liIter != li.end()) {
		if (*liIter % 2) { // Duplicate odd-valued elements
			liIter = li.insert(liIter, *liIter);
			liIter = std::next(liIter, 2);
		}
		else // Remove even-valued elements
			liIter = li.erase(liIter);
	}

	// forward_list
	auto fLiPrev = fLi.before_begin();
	auto fLiCurr = fLi.begin();
	while (fLiCurr != fLi.end()) {
		if (*fLiCurr % 2) { // Duplicate odd-valued elements
			fLiPrev = fLi.insert_after(fLiCurr, *fLiCurr);
			fLiCurr = std::next(fLiCurr, 2);
		}
		else // Remove even-valued elements
			fLiCurr = fLi.erase_after(fLiPrev);
	}

	// For testing
	std::cout << "list:";
	for (const auto& i1 : li)
		std::cout << " " << i1;
	std::cout << std::endl << "forward_list:";
	for (const auto& i2 : fLi)
		std::cout << " " << i2;

	return 0;
}
