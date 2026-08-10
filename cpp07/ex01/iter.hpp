
# pragma once

#include <cstdlib>

template <typename T, typename F> void	iter(T *ptr, const std::size_t len, F (&fun))
{
	if (ptr == NULL)
		return;
	for (std::size_t i = 0; i < len ; i++)
		fun(ptr[i]);
}
