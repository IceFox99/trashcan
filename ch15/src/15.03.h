#pragma once
#include <utility>
#include <string>
#include <iostream>

class Quote {
public:
	Quote() = default;
	Quote(const std::string& bookNo, double price) :
		bookNo(bookNo), price(price) {}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual void debug() const; // Exercise 15.11
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

inline double print_total(std::ostream& os, const Quote& item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}