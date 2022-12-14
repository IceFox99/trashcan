#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int aCnt, eCnt, iCnt, oCnt, uCnt;
	int spaceCnt, tabCnt, newlineCnt;
	aCnt = eCnt = iCnt = oCnt = uCnt = spaceCnt = tabCnt = newlineCnt = 0;
	char c;
	cout << "Please input a string: ";
	while (cin.get(c)) {
		switch (c)
		{
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newlineCnt;
			break;
		default:
			break;
		}
	}

	cout << "Number of vowel a: " << aCnt << endl;
	cout << "Number of vowel e: " << eCnt << endl;
	cout << "Number of vowel i: " << iCnt << endl;
	cout << "Number of vowel o: " << oCnt << endl;
	cout << "Number of vowel u: " << uCnt << endl;
	cout << "Number of space: " << spaceCnt << endl;
	cout << "Number of tab: " << tabCnt << endl;
	cout << "Number of new line: " << newlineCnt << endl;

	return 0;
}