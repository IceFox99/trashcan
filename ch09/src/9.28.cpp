#include <forward_list>
#include <iostream>

void insertStr(std::forward_list<std::string>& strFList, const std::string& str1, const std::string& str2) {
	auto prev = strFList.before_begin();
	auto curr = strFList.begin();
	while (curr != strFList.end()) {
		if (*curr == str1) {
			strFList.insert_after(curr, str2);
			return ;
		}
		prev = curr;
		++curr;
	}
	strFList.insert_after(prev, str2);
}

// For testing
//int main()
//{
//	std::forward_list<std::string> strFList{"shit", "fuck", "motherfucker"};
//	insertStr(strFList, "fuck", "you");
//	insertStr(strFList, "WTF", "bitch");
//
//	for (auto str : strFList)
//		std::cout << str << std::endl;
//	return 0;
//}