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
		int digitsGrade = grade % 10;
		score = (tensGrade < 6) ? scores[0] : scores[tensGrade - 5];
		score = (tensGrade < 6 || tensGrade == 10) ? score
			: (digitsGrade < 3) ? (score + "-")
			: (digitsGrade > 7) ? (score + "+")
			: score;

		cout << "Your score is " << score << "." << endl << endl;
		cout << "Please input your grade: ";
	}

	return 0;
}