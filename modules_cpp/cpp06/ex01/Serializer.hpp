#pragma once

#include <stdint.h>

struct Data;

class Serializer
{
private:
    Serializer(void);
    Serializer(const Serializer &cpy);
    Serializer &operator=(const Serializer &cpy);
    ~Serializer(void);

public:
    static uintptr_t serialize(Data *ptr);
    static Data     *deserialize(uintptr_t raw);
};
