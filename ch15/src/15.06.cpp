#include "15.03.h"
#include "15.05.h"

int main()
{
	Quote q("test1", 9.9);
	Bulk_quote bq("test2", 99.9, 3, 0.4);
	print_total(std::cout, q, 10);
	print_total(std::cout, bq, 5);
	return 0;
}