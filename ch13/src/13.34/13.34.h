#pragma once
#include <set>
#include <string>

class Folder;

class Message {
	friend class Folder;
	friend void swap(Message& m1, Message& m2);
public:
	explicit Message(const std::string& str = "") :
		contents(str) {}

	Message(const Message& m);
	Message& operator=(const Message& m);
	Message(Message&& m) noexcept; // Exercise 13.49
	Message& operator=(Message&& s) noexcept; // Exercise 13.49
	~Message();
	void save(Folder& f);
	void remove(Folder& f);

	void addFld(Folder* f);
	void remFld(Folder* f);
private:
	std::string contents;
	std::set<Folder*> folders;

	// Utility functions
	void add_to_Folders(const Message& m);
	void remove_from_Folders();
	void move_Folders(Message* m); // Exercise 13.49
};

class Folder {
	friend class Message;
	friend void swap(Folder& f1, Folder& f2);
public:
	Folder() = default;
	Folder(const Folder& f);
	Folder& operator=(const Folder& f);
	Folder(Folder&& f) noexcept; // Exercise 13.49
	Folder& operator=(Folder&& f) noexcept; // Exercise 13.49
	~Folder();
	void addMsg(Message* m);
	void remMsg(Message* m);
private:
	std::set<Message*> messages;

	// Utility functions
	void add_to_Messages(const Folder& f);
	void remove_from_Messages();
	void move_Messages(Folder* f); // Exercise 13.49
};

void swap(Message& m1, Message& m2);
void swap(Folder& f1, Folder& f2);