#include <map>
#include <string>
#include <vector>

int main()
{
	std::map<std::string, std::vector<int>> m;
	std::pair<std::map<std::string, std::vector<int>>::iterator, bool> p = m.insert(std::pair<std::string, std::vector<int>>("test", { 0, 1, 1, 2, 3 })); // return type and argument type
	return 0;
}