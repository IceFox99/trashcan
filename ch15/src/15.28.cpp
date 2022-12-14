#include <vector>
#include "15.27/15.27.h"

int main()
{
	Bulk_quote a("a", 10, 10, 0.3), b("b", 20, 3, 0.5), c("c", 50, 5, 0.7);
	std::vector<Quote> QVec{ a, b, c };
	double total_price = 0.0;
	for (const auto q : QVec)
		total_price += q.net_price(30);
	std::cout << "The total price is " << total_price << std::endl;
	return 0;
}