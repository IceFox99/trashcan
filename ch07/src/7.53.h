#pragma once
class Debug {
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
	constexpr Debug(bool hw, bool io, bool other) : hw(hw), io(io), other(other) {}
	constexpr bool any() { return hw || io || other; }
	void setHW(bool hw) { this->hw = hw; }
	void setIO(bool io) { this->io = io; }
	void setOTHER(bool other) { this->other = other; }
private:
	bool hw;
	bool io;
	bool other;
};