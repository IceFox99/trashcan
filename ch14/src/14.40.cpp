#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void printStrVecln(const std::vector<std::string>& strVec) {
	for (const auto& str : strVec)
		std::cout << str << " ";
	std::cout << std::endl;
}

void elimDups(std::vector<std::string>& strVec) {
	std::cout << "Before eliminating: ";
	printStrVecln(strVec);

	std::sort(strVec.begin(), strVec.end());
	std::cout << "After sorting: ";
	printStrVecln(strVec);

	auto end = std::unique(strVec.begin(), strVec.end());
	std::cout << "After unique: ";
	printStrVecln(strVec);

	strVec.erase(end, strVec.cend());
	std::cout << "After erasing: ";
	printStrVecln(strVec);
}

class ShorterSize {
public:
	bool operator()(const std::string& s1, const std::string& s2)
	{
		return s1.size() < s2.size();
	}
};

class IsLongerSize {
public:
	IsLongerSize(std::size_t sz) :
		sz(sz) {}
	bool operator()(const std::string& s)
	{
		return s.size() >= sz;
	}
private:
	std::size_t sz;
};

class PrintWithSpace {
public:
	void operator()(const std::string& s)
	{
		std::cout << s << " ";
	}
};

void biggies(std::vector<std::string>& strVec, std::vector<std::string>::size_type sz) {
	elimDups(strVec);

	std::stable_sort(strVec.begin(), strVec.end(), ShorterSize());
	std::cout << "After stable sorting: ";
	printStrVecln(strVec);

	auto begin = std::find_if(strVec.cbegin(), strVec.cend(), IsLongerSize(sz));
	auto count = strVec.cend() - begin;
	std::cout << "There are " << count << ((count > 1) ? " words " : " word ") << "whose length is no less than " << sz << "." << std::endl;

	std::cout << "After comparing: ";
	std::for_each(begin, strVec.cend(), PrintWithSpace());
	std::cout << std::endl;
}

int main()
{
	std::vector<std::string> strVec{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	biggies(strVec, 4);
	return 0;
}