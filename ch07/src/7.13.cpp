#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;

int main()
{
	Sales_data total = Sales_data(cin);
	if (cin) {
		Sales_data trans = Sales_data(cin);
		while (cin) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
			read(cin, trans);
		}
		print(cout, total) << endl;
	}
	else {
		cerr << "No data?" << endl;
	}
	return 0;
}