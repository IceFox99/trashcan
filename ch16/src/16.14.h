#pragma once
#include <string>
#include <iostream>

template <unsigned H, unsigned W> class Screen;

template <unsigned H, unsigned W>
std::istream& operator>>(std::istream& is, Screen<H, W>& s); // Exercise 16.15
template <unsigned H, unsigned W>
std::ostream& operator<<(std::ostream& os, const Screen<H, W>& s); // Exercise 16.15

template <unsigned H, unsigned W>
class Screen {
	friend std::istream& operator>><H, W>(std::istream& is, Screen<H, W>& s); // Exercise 16.15
	friend std::ostream& operator<<<H, W>(std::ostream& os, const Screen<H, W>& s); // Exercise 16.15
public:
	typedef std::string::size_type pos;
	Screen(char c = ' ') :
		contents(H* W, c) {}
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
	pos height = H, width = W;
	std::string contents;
	void do_display(std::ostream& os) const {
		os << contents;
	}
};

template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::set(char ch) {
	contents[cursor] = ch;
	return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::set(pos r, pos c, char ch) {
	contents[r * width + c] = ch;
	return *this;
}