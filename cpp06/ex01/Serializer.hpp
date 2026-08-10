
#pragma once

#include <stdint.h>

struct Data;

class Serializer
{
	private:
		uintptr_t	*_ptr;
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
