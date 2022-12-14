#include "../15.35.h"
#include <iostream>

int main()
{
	std::ifstream input("src/15.39/15.39.txt");
	TextQuery tq(input);
	Query q1 = Query("fiery") & Query("bird") | Query("wind");
	Query q2 = Query("fiery") & Query("bird");
	Query q3 = ~Query("her") | Query("daddy");
	Query q4 = Query("blahblah") | Query("wtf");
	std::cout << q1.eval(tq) << q2.eval(tq) << q3.eval(tq) << q4.eval(tq);
	return 0;
}