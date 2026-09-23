
#pragma once

#include <cstddef>   // for std::size_t

template <typename T, typename F>
void iter(T *array, std::size_t length, F func)
{
	if (array == NULL)
		return;
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}
