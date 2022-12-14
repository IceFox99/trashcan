#include <map>
#include <string>
#include <iostream>

int main()
{
	using map_type = std::map<int, std::string>;
	map_type m{ { 2017212985, "Hu Yuefeng"} }; // integer can be used to subscript the map, and string would be returned from the subscript operator.

	// General: key_type can be used to subscript the map, and mapped_type would be returned from the subscript operator.
	std::cout << "Type to subscript: " << typeid(map_type::key_type).name() << std::endl;
	std::cout << "Type returned from the subscript operator: " << typeid(decltype(m[2017212985])).name() << std::endl;
	return 0;
}