#include "13.34/13.34.h"

void Message::addFld(Folder* f)
{
	folders.insert(f);
}

void Message::remFld(Folder* f)
{
	folders.erase(f);
}