#pragma once
#include "15.03.h"
#include "15.05.h"

class Limit_quote : public Quote{
public:
	Limit_quote() = default;
	Limit_quote(const std::string& bookNo, double price, std::size_t limit, double discount) :
		Quote(bookNo, price), limit(limit), discount(discount) {}
	double net_price(std::size_t n) const override { return (n <= limit) ? n * price * (1 - discount) : limit * price * (1 - discount) + (n - limit) * price; }
private:
	std::size_t limit = 0;
	double discount = 0.0;
};