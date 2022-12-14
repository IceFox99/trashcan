#pragma once
#include "15.03.h"

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& bookNo, double price, std::size_t min_qty, double discount) :
		Quote(bookNo, price), min_qty(min_qty), discount(discount) {}
	double net_price(std::size_t n) const override { return n >= min_qty ? n * (1 - discount) * price : n * price; }
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};