#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	string str;
	cout << "Please input a string: ";
	while (getline(cin, str)) {
		for (auto c : str) {
			if (c == 'a')
				++aCnt;
			else if (c == 'e')
				++eCnt;
			else if (c == 'i')
				++iCnt;
			else if (c == 'o')
				++oCnt;
			else if (c == 'u')
				++uCnt;
		}
		cout << "Number of vowel a: " << aCnt << endl;
		cout << "Number of vowel e: " << eCnt << endl;
		cout << "Number of vowel i: " << iCnt << endl;
		cout << "Number of vowel o: " << oCnt << endl;
		cout << "Number of vowel u: " << uCnt << endl;

		aCnt = eCnt = iCnt = oCnt = uCnt = 0;
		cout << endl << "Please input a string: ";
	}
	return 0;
}