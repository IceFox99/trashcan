#include "15.35.h"
#include <iostream>

std::ostream& print(std::ostream& os, const QueryResult& qr, size_t first, size_t last) // Exercise 15.42.c
{
	if (first > last) {
		os << "Illegal range!";
		return os;
	}
	size_t count = 0;
	for (const auto& s : *qr.lines) {
		if (s >= first && s <= last)
			++count;
	}
	os << qr.word << " occurs " << count << " times" << std::endl;
	for (const auto& s : *qr.lines) {
		if (s >= first && s <= last)
			os << "\t(line " << s << ") " << qr.strVec.data->at(s - 1) << std::endl;
	}
	return os;
}

int main()
{
	std::ifstream input("src/15.39/15.39.txt");
	TextQuery tq(input);
	Query q1 = Query("fiery") & Query("bird") | Query("wind");
	Query q2 = ~Query("her") | Query("daddy");
	std::cout << q1.eval(tq) << q2.eval(tq);
	print(std::cout, q1.eval(tq), 1, 4);
	print(std::cout, q2.eval(tq), 3, 9);
	return 0;
}