
#pragma once

#include <exception>
#include <iterator>
#include <stdexcept>
#include <typeinfo>

template <typename T>
typename T::iterator easyfind(T &container, int second)
{
	if (typeid(typename T::value_type) != typeid(int))
		throw (std::runtime_error("Your container is not composed by int"));
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == second)
			return (it);
	}
	throw (std::runtime_error("The value was not found"));
}
