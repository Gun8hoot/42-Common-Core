
#include "Serializer.hpp"
#include <inttypes.h>

uintptr_t	Serializer::serialize(Data *ptr)
{
	if (!ptr)
		return (static_cast<uintptr_t>(0));
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	if (!raw)
		return (static_cast<Data *>(0));
	return (reinterpret_cast<Data *>(raw));
}
