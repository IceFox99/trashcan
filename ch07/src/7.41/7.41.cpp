#include "7.41.h"
#include <iostream>
using std::string; using std::istream; using std::ostream;

Sales_data_delegating::Sales_data_delegating(const string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n* p) {
	std::cout << "You are using the Sales_data(const string&, unsigned, double) method!" << std::endl;
}

Sales_data_delegating::Sales_data_delegating() : Sales_data_delegating("", 0, 0) {
	std::cout << "You are using the Sales_data() method!" << std::endl;
}

Sales_data_delegating::Sales_data_delegating(const string& s) : Sales_data_delegating(s, 0, 0) {
	std::cout << "You are using the Sales_data(const string&) method!" << std::endl;
}

Sales_data_delegating::Sales_data_delegating(istream& is) : Sales_data_delegating() {
	read(is, *this);
	std::cout << "You are using the Sales_data(istream&) method!" << std::endl;
}

string Sales_data_delegating::isbn() const {
	return bookNo;
}

unsigned Sales_data_delegating::getUnitsSold() const {
	return units_sold;
}

double Sales_data_delegating::getRevenue() const {
	return revenue;
}

Sales_data_delegating& Sales_data_delegating::combine(const Sales_data_delegating& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

inline double Sales_data_delegating::avg_price() const {
	return units_sold ? revenue / units_sold : 0;
}

Sales_data_delegating add(const Sales_data_delegating& lhs, const Sales_data_delegating& rhs) {
	Sales_data_delegating sum = lhs;
	sum.combine(rhs);
	return sum;
}

istream& read(istream& is, Sales_data_delegating& item) {
	string bookNo;
	unsigned units_sold = 0;
	double price = 0.0;
	is >> bookNo >> units_sold >> price;
	item.bookNo = bookNo;
	item.units_sold = units_sold;
	item.revenue = units_sold * price;
	return is;
}

ostream& print(ostream& os, const Sales_data_delegating& item) {
	os << item.isbn() << " " << item.getUnitsSold() << " "
		<< item.getRevenue() << " " << item.avg_price();
	return os;
}