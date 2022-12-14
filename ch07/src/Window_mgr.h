#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Screen.h"

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex i);
private:
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
};

void Window_mgr::clear(ScreenIndex i) {
	Screen& s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}
