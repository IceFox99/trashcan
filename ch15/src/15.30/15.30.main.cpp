#include "15.30.h"

int main()
{
	Bulk_quote a("a", 10, 10, 0.3), b("b", 20, 3, 0.5), c("c", 50, 5, 0.7);
	Basket bas;
	for (int i = 0; i != 30; ++i) {
		bas.add_item(a);
		bas.add_item(b);
		bas.add_item(c);
	}
	bas.total_receipt(std::cout);
	return 0;
}