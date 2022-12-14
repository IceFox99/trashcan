#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::string; using std::vector; using std::begin; using std::end;

class Screen_test;

class Window_mgr_test {
public:
	void clear(Screen_test& s);
};

class Screen_test {
	friend void Window_mgr_test::clear(Screen_test& s);
public:
	typedef std::string::size_type pos;
	Screen_test() = default;
	Screen_test(pos ht, pos wd, char c = ' ') :
		height(ht), width(wd), contents(ht* wd, c) {}
	char get() const {
		return contents[cursor];
	}
	char get(pos r, pos c) const {
		return contents[c + r * width];
	}
	std::string getContents() const {
		return contents;
	}
	Screen_test& move(pos r, pos c);
	Screen_test& set(char ch);
	Screen_test& set(pos r, pos c, char ch);
	Screen_test& display(std::ostream& os) {
		do_display(os);
		return *this;
	}
	const Screen_test& display(std::ostream& os) const {
		do_display(os);
		return *this;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream& os) const {
		os << contents;
	}
};

inline Screen_test& Screen_test::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline Screen_test& Screen_test::set(char ch) {
	contents[cursor] = ch;
	return *this;
}

inline Screen_test& Screen_test::set(pos r, pos c, char ch) {
	contents[r * width + c] = ch;
	return *this;
}

void Window_mgr_test::clear(Screen_test& s) {
	s.contents = " ";
}

int main()
{
	Screen_test s(5, 5, 'X');
	s.display(cout);
	cout << endl;

	Window_mgr_test w;
	w.clear(s);
	s.display(cout);
	return 0;
}