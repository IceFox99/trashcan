#pragma once
#include "16.12.h"

template <typename T>
template <typename Iter>
Blob<T>::Blob(Iter beg, Iter end) :
	data(std::make_shared<std::vector<T>>(beg, end)) {};