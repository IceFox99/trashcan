#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::vector; using std::begin; using std::end;

int main()
{
	Sales_data total;
	cout << "Please input a record: ";
	if (read(cin, total)) {
		Sales_data trans;
		cout << "Please input a record: ";
		while (read(cin, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total);
				cout << endl;
				total = trans;
			}
			cout << "Please input a record: ";
		}
		print(cout, total);
		cout << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}