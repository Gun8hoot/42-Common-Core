
#include "Serializer.hpp"
#include "Data.hpp"

#include <inttypes.h>
#include <iostream>

int main(void)
{
	Data		data;
	Data		*ptr_data;
	uintptr_t	ptr_to;

	data.data = 0xFF;

	{
		ptr_to = Serializer::serialize(&data);
		ptr_data = Serializer::deserialize(ptr_to);

		std::cout	<< "Original data struct :" << std::endl
					<< "\taddress = " << &data << std::endl
					<< "\tcontent = " << data.data << std::endl;

		std::cout	<< std::endl;
		std::cout	<< "uintptr_t content = " << ptr_data << std::endl;
		std::cout	<< std::endl;

		std::cout	<< "ptr_data data struct :" << std::endl
					<< "\taddress = " << ptr_data << std::endl
					<< "\tcontent = " << ptr_data->data << std::endl;
	}
}
