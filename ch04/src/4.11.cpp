#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	int a, b, c, d;
	cout << "Please input a's value: ";
	cin >> a;
	cout << "Please input b's value: ";
	cin >> b;
	cout << "Please input c's value: ";
	cin >> c;
	cout << "Please input d's value: ";
	cin >> d;

	if (a > b && b > c && c > d)
		cout << "Nice!" << endl;
	else
		cout << "Fuck!" << endl;

	return 0;
}