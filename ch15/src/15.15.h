#pragma once
#include "15.03.h"

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& bookNo, double price, std::size_t quantity, double discount) :
		Quote(bookNo, price), quantity(quantity), discount(discount) {}
	virtual double net_price(std::size_t n) const override = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& bookNo, double price, std::size_t quantity, double discount) :
		Disc_quote(bookNo, price, quantity, discount) {}
	double net_price(std::size_t n) const override { return n >= quantity ? n * (1 - discount) * price : n * price; }
};