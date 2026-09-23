
#include "Serializer.hpp"
#include "Data.hpp"

#include <stdint.h>
#include <iostream>

int main(void)
{
    Data      data;
    Data     *ptr_data;
    uintptr_t ptr_to;

    data.data = 0xFF;

    ptr_to   = Serializer::serialize(&data);
    ptr_data = Serializer::deserialize(ptr_to);

    std::cout << "Original data struct :" << std::endl
              << "\taddress = " << &data       << std::endl
              << "\tcontent = " << data.data   << std::endl;

    std::cout << std::endl;
    std::cout << "uintptr_t content = " << ptr_to << std::endl;
    std::cout << std::endl;

    std::cout << "ptr_data data struct :" << std::endl
              << "\taddress = " << ptr_data         << std::endl
              << "\tcontent = " << ptr_data->data   << std::endl;

    if (ptr_data == &data)
        std::cout << "\ndeserialize(serialize(&data)) == &data" << std::endl;
    else
        std::cout << "\npointers do not match" << std::endl;

    return 0;
}
