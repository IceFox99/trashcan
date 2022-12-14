#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include "../include/Sales_item.h"

inline bool compIsbn(const Sales_item& s1, const Sales_item& s2) {
	return std::stoi(s1.isbn()) < std::stoi(s2.isbn());
}

int main()
{
	std::vector<Sales_item> siVec;
	std::istream_iterator<Sales_item> si_iter(std::cin), eof;
	std::ostream_iterator<Sales_item> output(std::cout, "\n");

	while (si_iter != eof)
		siVec.push_back(*si_iter++);

	if (!siVec.empty()) {
		std::sort(siVec.begin(), siVec.end(), compIsbn);

		auto iter = siVec.begin();
		while (iter != siVec.end()) {
			auto isbn = iter->isbn();
			auto next = std::find_if_not(iter + 1, siVec.end(), [isbn](const Sales_item& si) {
				return si.isbn() == isbn;
				});
			if (next != iter + 1) {
				*iter = std::accumulate(iter, next, Sales_item(isbn));
				siVec.erase(iter + 1, next);
			}
			++iter;
		}

		for (const auto& si : siVec)
			*output++ = si;
	}
	return 0;
}