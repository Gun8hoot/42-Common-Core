
#include "Array.hpp"
#include <exception>
#include <sys/types.h>
#include <typeinfo>

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
	{
		std::cout << std::endl <<  "//// CREATING AN ARRAY WITH 5 ELEMENT \\\\\\\\" << std::endl;
		Array<int> arr(5);

		std::cout << std::endl <<  "//// DISPLAY THE ARRAY \\\\\\\\" << std::endl;
		show_array(arr);

		std::cout << std::endl <<  "//// ASSIGN 2 AT 0 AND 3 AT 1 \\\\\\\\" << std::endl;
		arr[0] = 2;
		arr[1] = 3;

		std::cout << std::endl <<  "//// DISPLAY THE ARRAY \\\\\\\\" << std::endl;
		show_array(arr);

		std::cout << std::endl <<  "//// TRYING TO GO OUT OF BOUND \\\\\\\\" << std::endl;
		try
		{
			std::cout << arr[25];
		}
		catch (std::exception &ex)
		{
			std::cout << "Err : " << ex.what() << std::endl;
		}

		std::cout << std::endl <<  "//// TRYING TO ASSIGN VALUE AT AN OUT OF BOUND POS \\\\\\\\" << std::endl;
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
		std::cout << std::endl <<  "//// NO PARAMETER CONSTRUCTOR \\\\\\\\" << std::endl;
		Array<char>	c(0);

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
		std::cout << std::endl <<  "//// COPY & ASSIGNEMENT CONSTRUCTOR \\\\\\\\" << std::endl;
		Array<char>	c(5);

		c[0] = 'a';
		c[1] = 'b';
		c[2] = 'c';
		c[3] = 'd';
		c[4] = 'e';

		Array<char> ptr1 = c;
		Array<char> ptr2(c);

		std::cout << std::endl <<  "//// SHOW INITIAL ARRAY \\\\\\\\" << std::endl;
		show_array(c);

		std::cout << std::endl <<  "//// SHOW THE ASSIGNEMENT CONSTRUCTOR ARRAY \\\\\\\\" << std::endl;
		show_array(ptr1);

		std::cout << std::endl <<  "//// SHOW THE COPY CONSTRUCTOR ARRAY \\\\\\\\" << std::endl;
		show_array(ptr2);
	}
}
