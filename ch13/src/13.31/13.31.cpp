#include "13.31.h"
#include <vector>
#include <algorithm>

void swap(HasPtr& lhp, HasPtr& rhp) {
	std::cout << "Call function swap(HasPtr& lhp, HasPtr& rhp) to \"" << *lhp.ps << "\" and \"" << *rhp.ps << "\"." << std::endl;
	using std::swap;
	swap(lhp.ps, rhp.ps);
	swap(lhp.i, rhp.i);
}

bool operator<(const HasPtr& lhp, const HasPtr& rhp) {
	return *lhp.ps < *rhp.ps;
}

int main()
{
	HasPtr a("Hello"), b("World"), c("Buddy");
	std::vector<HasPtr> hpVec{ a, b, c };

	std::cout << "Before sorting:" << std::endl;
	for (auto hp : hpVec)
		hp.print();

	std::sort(hpVec.begin(), hpVec.end());
	std::cout << "After sorting:" << std::endl;
	for (auto hp : hpVec)
		hp.print();

	return 0;
}