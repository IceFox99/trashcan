#include "StrBlob.h"

class StrBlobPtrPtr {
public:
	StrBlobPtrPtr() = default;
	StrBlobPtrPtr(StrBlobPtr* sbpPtr) :
		sbpPtr(sbpPtr) {}

	StrBlobPtr& operator*()
	{
		return *sbpPtr;
	}

	StrBlobPtr* operator->()
	{
		return sbpPtr;
	}
private:
	StrBlobPtr* sbpPtr = nullptr;
};