#pragma once
#include <iostream>
#include <string>

class Book {
	friend std::istream& read(std::istream& is, Book& book);
private:
	std::string isbn;
	int price;
	std::string press;
	std::string author;
	int pages;
public:
	Book(const std::string& isbn, const std::string& author, const std::string& press, int price, int pages) :
		isbn(isbn), author(author), press(press), price(price), pages(pages) {
		std::cout << "You are using the Book(const string&, const string&, const string&, int, int) method!" << std::endl;
	}
	Book() : Book("", "", "", 0, 0) {
		std::cout << "You are using the Book() method!" << std::endl;
	}
	Book(std::istream& is) : Book() {
		read(is, *this);
		std::cout << "You are using the Book(istream&) method!" << std::endl;
	}
};

std::istream& read(std::istream& is, Book& book) {
	std::string isbn;
	int price;
	std::string press;
	std::string author;
	int pages;
	is >> isbn >> author >> press >> price >> pages;
	book.isbn = isbn;
	book.author = author;
	book.press = press;
	book.price = price;
	book.pages = pages;
	return is;
}