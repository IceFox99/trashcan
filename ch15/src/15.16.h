#pragma once
#include "15.15.h"

class quantity_quote : public Disc_quote {
public:
	quantity_quote() = default;
	quantity_quote(const std::string& bookNo, double price, std::size_t quantity, double discount) :
		Disc_quote(bookNo, price, quantity, discount) {}
	double net_price(std::size_t n) const override { return (n <= quantity) ? n * price * (1 - discount) : quantity * price * (1 - discount) + (n - quantity) * price; }
};