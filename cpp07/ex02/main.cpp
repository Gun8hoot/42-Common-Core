
#include "Array.hpp"
#include <exception>
#include <sys/types.h>
#include <typeinfo>

#define GREEN "\x1b[32m";
#define RED "\x1b[31m";
#define RESET "\x1b[0m";

template <typename T> void	show_array(Array<T> &arr) throw ()
{
	std::size_t	sz = arr.size();

	if (sz == 0)
	{
		std::cout << "The array is empty." << std::endl;
		return;
	}
	std::cout << "Array :" << std::endl;
	for (std::size_t i = 0 ; i < sz ; i++)
		std::cout	<< "\t" << i << ": " << arr[i] << std::endl;
}

int main(void)
{
	std::cout << std::endl <<  "\x1b[32m//// FIRST TESTS \\\\\\\\\x1b[0m" << std::endl;
	{
		std::cout << std::endl <<  "\x1b[32m//// CREATING AN ARRAY WITH 5 ELEMENT \\\\\\\\\x1b[0m" << std::endl;
		Array<int> arr(5);

		std::cout << std::endl <<  "\x1b[32m//// DISPLAY THE ARRAY \\\\\\\\\x1b[0m" << std::endl;
		show_array(arr);

		arr[0] = 2;
		arr[1] = 3;

		std::cout << std::endl <<  "\x1b[32m//// DISPLAY THE ARRAY \\\\\\\\\x1b[0m" << std::endl;
		show_array(arr);

		std::cout << std::endl <<  "\x1b[32m//// TRYING TO GO OUT OF BOUND \\\\\\\\\x1b[0m" << std::endl;
		try
		{
			std::cout << arr[25];
		}
		catch (std::exception &ex)
		{
			std::cout << "\x1b[31mErr : " << ex.what() << "\x1b[0m" <<  std::endl;
		}

		std::cout << std::endl <<  "\x1b[32m//// TRYING TO ASSIGN VALUE AT AN OUT OF BOUND POS \\\\\\\\\x1b[0m" << std::endl;
		try
		{
			arr[444] = 0xff;
		}
		catch (std::exception &ex)
		{
			std::cout << "\x1b[31mErr : " << ex.what() << "\x1b[0m" <<  std::endl;
		}
	}

	{
		std::cout << std::endl <<  "\x1b[32m//// NO PARAMETER CONSTRUCTOR \\\\\\\\\x1b[0m" << std::endl;
		Array<char>	c(0);

		try
		{
			c[0] = 'A';
			std::cout << c[0] << std::endl;
		}
		catch (std::exception &ex)
		{
			std::cout << "\x1b[31mErr : " << ex.what() << "\x1b[0m" <<  std::endl;
		}
		show_array(c);
	}

	{
		std::cout << std::endl <<  "\x1b[32m//// COPY & ASSIGNEMENT CONSTRUCTOR \\\\\\\\\x1b[0m" << std::endl;
		Array<char>	c(5);

		c[0] = 'a';
		c[1] = 'b';
		c[2] = 'c';
		c[3] = 'd';
		c[4] = 'e';

		Array<char> ptr1 = c;
		Array<char> ptr2(c);

		std::cout << std::endl <<  "\x1b[32m//// SHOW INITIAL ARRAY \\\\\\\\\x1b[0m" << std::endl;
		show_array(c);
		std::cout << &c << std::endl;

		std::cout << std::endl <<  "\x1b[32m//// SHOW THE ASSIGNEMENT CONSTRUCTOR ARRAY \\\\\\\\\x1b[0m" << std::endl;
		show_array(ptr1);
		std::cout << &ptr1 << std::endl;

		std::cout << std::endl <<  "\x1b[32m//// SHOW THE COPY CONSTRUCTOR ARRAY \\\\\\\\\x1b[0m" << std::endl;
		show_array(ptr2);
		std::cout << &ptr2 << std::endl;
	}
}
