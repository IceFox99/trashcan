#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	string cStr, nStr, tempStr;
	vector<string> finalStr;
	int tempNum = 1, finalNum = 1;
	cout << "Please input some strings: ";
	cin >> cStr;
	while (cin >> nStr) {
		if (nStr == cStr) {
			tempStr = nStr;
			++tempNum;
		}
		else {
			if (tempNum > finalNum) {
				finalStr.clear();
				finalStr.push_back(tempStr);
				finalNum = tempNum;
			}
			else if (tempNum == finalNum && tempNum > 1)
				finalStr.push_back(tempStr);
			tempNum = 1;
		}
		cStr = nStr;
	}
	if (tempNum > finalNum) {
		finalStr.clear();
		finalStr.push_back(tempStr);
		finalNum = tempNum;
	}
	else if (tempNum == finalNum && tempNum > 1)
		finalStr.push_back(tempStr);

	if (finalNum == 1)
		cout << "No repeated strings!" << endl;
	else {
		for (auto str : finalStr)
			cout << "String \"" << str << "\" repeat " << finalNum << " times!" << endl;
	}
	return 0;
}