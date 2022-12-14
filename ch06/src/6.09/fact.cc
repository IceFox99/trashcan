#include "Chapter6.h"

int fact(int num) {
	int result = 1;
	for (int i = num; i != 1; --i)
		result *= i;
	return result;
}