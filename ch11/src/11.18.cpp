#include <map>
#include <string>
#include <iostream>

int main()
{
	std::map<std::string, std::size_t> word_count;
	std::map<std::string, std::size_t>::const_iterator map_it = word_count.cbegin();
	return 0;
}