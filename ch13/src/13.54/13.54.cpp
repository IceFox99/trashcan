#include "13.54.h"
#include <vector>
#include <algorithm>

void swap(HasPtr& lhp, HasPtr& rhp)
{
	std::cout << "Call function swap(HasPtr& lhp, HasPtr& rhp) to \"" << *lhp.ps << "\" and \"" << *rhp.ps << "\"." << std::endl;
	using std::swap;
	swap(lhp.ps, rhp.ps);
	swap(lhp.i, rhp.i);
}

bool operator<(const HasPtr& lhp, const HasPtr& rhp)
{
	return *lhp.ps < *rhp.ps;
}

HasPtr::HasPtr(const HasPtr& t) :
	ps(new std::string(*t.ps)), i(t.i)
{
	std::cout << "Copy constructor called." << std::endl;
}

HasPtr::HasPtr(HasPtr&& t) noexcept :
	ps(t.ps), i(t.i)
{
	t.ps = nullptr;
	std::cout << "Move constructor called." << std::endl;
}

//HasPtr& HasPtr::operator=(const HasPtr& t)
//{
//	if (this != &t) {
//		delete ps;
//		ps = t.ps;
//		i = t.i;
//	}
//	std::cout << "Copy assignment called." << std::endl;
//	return *this;
//}

HasPtr& HasPtr::operator=(HasPtr&& t) noexcept
{
	if (this != &t) {
		delete ps;
		ps = t.ps;
		i = t.i;
		t.ps = nullptr;
	}
	std::cout << "Move assignment called." << std::endl;
	return *this;
}

int main()
{
	// ****************** 'operator =' is ambiguous ******************

	HasPtr a("Hello"), b("World"), c("Buddy");
	std::vector<HasPtr> hpVec;
	hpVec.reserve(3);
	hpVec.push_back(std::move(a));
	hpVec.push_back(std::move(b));
	hpVec.push_back(std::move(c));

	std::cout << "Before sorting:" << std::endl;
	for (auto& hp : hpVec)
		hp.print();

	std::sort(hpVec.begin(), hpVec.end());
	std::cout << "After sorting:" << std::endl;
	for (auto& hp : hpVec)
		hp.print();

	return 0;
}