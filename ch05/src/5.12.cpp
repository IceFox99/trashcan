#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int ffCnt, flCnt, fiCnt;
	ffCnt = flCnt = fiCnt = 0;
	char c;
	bool f = false;
	cout << "Please input a string: ";
	while (cin >> c) {
		if (!f) {
			if (c == 'f')
				f = true;
		}
		else {
			switch (c)
			{
			case 'f':
				++ffCnt;
				break;
			case 'l':
				++flCnt;
				break;
			case 'i':
				++fiCnt;
				break;
			default:
				break;
			}
			f = false;
		}
	}

	cout << "Number of ff: " << ffCnt << endl;
	cout << "Number of fl: " << flCnt << endl;
	cout << "Number of fi: " << fiCnt << endl;

	return 0;
}