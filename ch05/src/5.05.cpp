#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;
using std::begin; using std::end;

int main()
{
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	int grade;
	string score;
	cout << "Please input your grade: ";
	while (cin >> grade) {
		int tensGrade = grade / 10;
		if (tensGrade == 10)
			score = scores[tensGrade - 5];
		else if (tensGrade < 6)
			score = scores[0];
		else {
			int digitsGrade = grade % 10;
			score = scores[tensGrade - 5];
			if (digitsGrade < 3)
				score += "-";
			else if (digitsGrade > 7)
				score += "+";
		}

		cout << "Your score is " << score << "." << endl << endl;
		cout << "Please input your grade: ";
	}
	return 0;
}