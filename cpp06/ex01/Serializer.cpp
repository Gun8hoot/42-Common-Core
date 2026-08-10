
#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *ptr)
{
	if (!ptr)
		return (0);
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	if (!raw)
		return (static_cast<Data *>(0));
	return (reinterpret_cast<Data *>(raw));
}
