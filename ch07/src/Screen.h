#pragma once
#include <string>
#include <iostream>

class Screen {
	friend class Window_mgr;
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c = ' ') :
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
	Screen& move(pos r, pos c);
	Screen& set(char ch);
	Screen& set(pos r, pos c, char ch);
	Screen& display(std::ostream& os) {
		do_display(os);
		return *this;
	}
	const Screen& display(std::ostream& os) const {
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

inline Screen& Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline Screen& Screen::set(char ch) {
	contents[cursor] = ch;
	return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch) {
	contents[r * width + c] = ch;
	return *this;
}
