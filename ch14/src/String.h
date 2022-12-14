#pragma once
#include <utility>
#include <memory>

class String {
	friend bool operator==(const String& lhs, const String& rhs);
	friend bool operator!=(const String& lhs, const String& rhs);
	friend bool operator<(const String& lhs, const String& rhs);
	friend bool operator>(const String& lhs, const String& rhs);
public:
	String() :
		beg(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char* str);
	String(const String& s);
	String& operator=(const String& s);
	String(String&& s) noexcept; // Exercise 13.49
	String& operator=(String&& s) noexcept; // Exercise 13.49
	char& operator[](std::size_t n); // Exercise 14.26
	const char& operator[](std::size_t n) const; // Exercise 14.26
	~String();

	std::size_t size() const { return first_free - beg; }
	std::size_t capacity() const { return cap - beg; }
	char* begin() const { return beg; }
	char* end() const { return first_free; }
	const char* c_str() const { return beg; }

	void push_back(char c);
	void reserve(std::size_t new_cap);
	void resize(std::size_t count, char new_ch = '\0');
private:
	std::allocator<char> alloc;
	char* beg;
	char* first_free;
	char* cap;

	// Utility function
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	void free();
	void reallocate();
	std::pair<char*, char*> alloc_n_copy(const char* b, const char* e);
	void alloc_n_move(std::size_t new_capacity);
};

bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);