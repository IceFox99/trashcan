#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../Sales_data.h"

int main(int argc, char* argv[])
{
	std::ifstream input(argv[1]); // "src/8.06/8.06.txt"
	std::ofstream output(argv[2]); // "src/8.07/8.07.txt"
	if (input && output) {
		Sales_data total; // variable to hold the running sum
		if (read(input, total)) { // read the first transaction
			Sales_data trans; // variable to hold data for the next transaction
			while (read(input, trans)) { // read the remaining transactions
				if (total.isbn() == trans.isbn()) // check the isbns
					total.combine(trans); // update the running total
				else {
					print(output, total) << std::endl; // print the results
					total = trans; // process the next book
				}
			}
			print(output, total) << std::endl; // print the last transaction
		}
		else { // there was no input
			std::cerr << "No data?!" << std::endl; // notify the user
		}
	}

	output.close();

	return 0;
}