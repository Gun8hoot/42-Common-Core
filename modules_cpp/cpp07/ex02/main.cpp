#include "Array.hpp"
#include <iostream>
#include <string>

template <typename T>
void show_array(const Array<T> &arr)
{
	std::size_t sz = arr.size();
	if (sz == 0)
	{
		std::cout << "The array is empty." << std::endl;
		return;
	}
	std::cout << "Array :" << std::endl;
	for (std::size_t i = 0; i < sz; ++i)
		std::cout << "\t" << i << ": " << arr[i] << std::endl;
}

int main(void)
{
	std::cout << "\n//// FIRST TESTS \\\\" << std::endl;
	{
		std::cout << "\n//// CREATING AN ARRAY WITH 5 ELEMENTS \\\\" << std::endl;
		Array<int> arr(5);
		show_array(arr);

		arr[0] = 2;
		arr[1] = 3;
		show_array(arr);

		std::cout << "\n//// TRYING TO GO OUT OF BOUNDS \\\\" << std::endl;
		try
		{
			std::cout << arr[25];
		}
		catch (std::exception &ex)
		{
			std::cout << "Err : " << ex.what() << std::endl;
		}

		std::cout << "\n//// TRYING TO ASSIGN OUT OF BOUNDS \\\\" << std::endl;
		try
		{
			arr[444] = 0xff;
		}
		catch (std::exception &ex)
		{
			std::cout << "Err : " << ex.what() << std::endl;
		}
	}

	{
		std::cout << "\n//// NO PARAMETER CONSTRUCTOR \\\\" << std::endl;
		Array<char> c(0);
		try
		{
			c[0] = 'A';
			std::cout << c[0] << std::endl;
		}
		catch (std::exception &ex)
		{
			std::cout << "Err : " << ex.what() << std::endl;
		}
		show_array(c);
	}

	{
		std::cout << "\n//// COPY & ASSIGNMENT CONSTRUCTOR \\\\" << std::endl;
		Array<char> c(5);
		c[0] = 'a';
		c[1] = 'b';
		c[2] = 'c';
		c[3] = 'd';
		c[4] = 'e';

		Array<char> ptr1 = c;   // copy constructor
		Array<char> ptr2(c);    // copy constructor

		std::cout << "\n//// SHOW INITIAL ARRAY \\\\" << std::endl;
		show_array(c);
		std::cout << "Address of c:    " << &c << std::endl;

		std::cout << "\n//// SHOW COPY CONSTRUCTOR ARRAY \\\\" << std::endl;
		show_array(ptr1);
		std::cout << "Address of ptr1: " << &ptr1 << std::endl;

		std::cout << "\n//// SHOW COPY CONSTRUCTOR ARRAY \\\\" << std::endl;
		show_array(ptr2);
		std::cout << "Address of ptr2: " << &ptr2 << std::endl;

		// Test assignment operator
		std::cout << "\n//// ASSIGNMENT OPERATOR \\\\" << std::endl;
		Array<char> ptr3;
		ptr3 = c;
		show_array(ptr3);
		std::cout << "Address of ptr3: " << &ptr3 << std::endl;
	}

	return 0;
}
