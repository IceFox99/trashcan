#include "13.39/13.39.h"
#include "13.44/13.44.h"
#include "13.34/13.34.h"
#include <iostream>

StrVec::StrVec(StrVec&& sv) noexcept :
	elements(sv.elements), first_free(sv.first_free), cap(sv.cap)
{
	sv.elements = sv.first_free = sv.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&& sv) noexcept
{
	if (this != &sv) {
		free();
		elements = sv.elements;
		first_free = sv.first_free;
		cap = sv.cap;
		sv.elements = sv.first_free = sv.cap = nullptr;
	}
	return *this;
}

String::String(String&& s) noexcept
	: beg(s.beg), first_free(s.first_free), cap(s.cap)
{
	s.beg = s.first_free = s.cap = nullptr;
	std::cout << "Move constructor called." << std::endl;
}

String& String::operator=(String&& s) noexcept
{
	if (this != &s) {
		free();
		beg = s.beg;
		first_free = s.first_free;
		cap = s.cap;
		s.beg = s.first_free = s.cap = nullptr;
	}
	std::cout << "Move assignment called." << std::endl;
	return *this;
}

void Message::move_Folders(Message* m)
{
	folders = std::move(m->folders);
	for (auto f : folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

Message::Message(Message&& m) noexcept :
	contents(std::move(m.contents))
{
	move_Folders(&m);
}

Message& Message::operator=(Message&& m) noexcept
{
	if (this != &m) {
		remove_from_Folders();
		contents = std::move(m.contents);
		move_Folders(&m);
	}
	return *this;
}

void Folder::move_Messages(Folder* f)
{
	messages = std::move(f->messages);
	for (auto m : messages) {
		m->remFld(f);
		m->addFld(this);
	}
	f->messages.clear();
}

Folder::Folder(Folder&& f) noexcept
{
	move_Messages(&f);
}

Folder& Folder::operator=(Folder&& f) noexcept
{
	if (this != &f) {
		remove_from_Messages();
		move_Messages(&f);
	}
	return *this;
}