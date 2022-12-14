#include <map>
#include <string>
#include <iostream>

int main()
{
	// count the number of times each word occurs in the input
	std::map<std::string, std::size_t> word_count; // empty map from string to std::size_t
	std::string word;
	while (std::cin >> word) {
		// fetch and increment the counter for word
		//++word_count[word]; // Original way.
		//++word_count.insert({ word, 0 }).first->second; // Another artful way.
		auto p = word_count.insert({ word, 1 });
		if (!p.second)
			++(p.first->second);
	}

	for (const auto& w : word_count) // for each element in the map
	// print the results
		std::cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times" : " time") << std::endl;
	return 0;
}