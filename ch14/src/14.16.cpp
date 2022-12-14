#include "StrBlob.h"
#include "StrVec.h"
#include "String.h"

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs == rhs);
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

bool operator==(const StrVec& lhs, const StrVec& rhs)
{
	if (lhs.size() != rhs.size() || lhs.capacity() != rhs.capacity())
		return false;
	else {
		auto lPtr = lhs.begin(), rPtr = rhs.begin();
		for (std::size_t i = 0; i != lhs.size(); ++i) {
			if (*lPtr++ != *rPtr++)
				return false;
		}
		return true;
	}
}

bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
	return !(lhs == rhs);
}

bool operator==(const String& lhs, const String& rhs)
{
	if (lhs.size() != rhs.size() || lhs.capacity() != rhs.capacity())
		return false;
	else {
		auto lPtr = lhs.begin(), rPtr = rhs.begin();
		for (std::size_t i = 0; i != lhs.size(); ++i) {
			if (*lPtr++ != *rPtr++)
				return false;
		}
		return true;
	}
}

bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}