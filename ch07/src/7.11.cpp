#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"
using std::cin; using std::cout; using std::endl;
using std::string; using std::vector; using std::begin; using std::end;

int main()
{
	Sales_data s1 = Sales_data();
	Sales_data s2 = Sales_data("s2");
	Sales_data s3 = Sales_data("s3", 5, 30.0);

	cout << s1.isbn() << " " << s1.getRevenue() << endl;
	cout << s2.isbn() << " " << s2.getRevenue() << endl;
	cout << s3.isbn() << " " << s3.getRevenue() << endl;
	return 0;
}