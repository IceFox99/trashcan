#include "13.34/13.34.h"

Folder::Folder(const Folder& f)
{
	add_to_Messages(f);
}

Folder& Folder::operator=(const Folder& f)
{
	remove_from_Messages();
	messages = f.messages;
	add_to_Messages(f);
	return *this;
}

Folder::~Folder()
{
	remove_from_Messages();
}

void Folder::addMsg(Message* m)
{
	messages.insert(m);
}

void Folder::remMsg(Message* m)
{
	messages.erase(m);
}

void Folder::add_to_Messages(const Folder& f)
{
	for (auto m : f.messages)
		m->save(*this);
}

void Folder::remove_from_Messages()
{
	for (auto m : messages)
		m->remove(*this);
}

void swap(Folder& f1, Folder& f2)
{
	using std::swap;
	for (auto m : f1.messages)
		m->remove(f1);
	for (auto m : f2.messages)
		m->remove(f2);
	swap(f1.messages, f2.messages);
	for (auto m : f1.messages)
		m->save(f1);
	for (auto m : f2.messages)
		m->save(f2);
}