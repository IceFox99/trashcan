#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
	std::ifstream input("src/10.33/input.txt");
	std::ofstream even("src/10.33/even.txt"), odd("src/10.33/odd.txt");
	std::istream_iterator<int> input_iter(input), eof;
	std::ostream_iterator<int> even_iter(even, "\n"), odd_iter(odd, " ");

	// for_each instead of traditional loop:
	std::for_each(input_iter, eof, [&even_iter, &odd_iter](const int i) {
		*(i % 2 ? odd_iter : even_iter)++ = i;
		});

	// Loop version:
	/*while (input_iter != eof) {
		auto num = *input_iter;
		if (num % 2) // Odd number
			odd_iter = num;
		else // Even number
			even_iter = num;
		++input_iter;
	}*/
	return 0;
}