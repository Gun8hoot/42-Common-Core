
#include "Array.hpp"
#include <typeinfo>

void	show_array(Array<int> &arr)
{
	std::size_t	sz = arr.size();

	std::cout << "Array :" << std::endl;
	for (std::size_t i = 0 ; i < sz ; i++)
		std::cout	<< "\t" << i << ": " << arr[i] << std::endl;
}

int main(void)
{
	Array<int> aaa(5);

	aaa[0] = 2;
	aaa[1] = 3;
	show_array(aaa);
	Array<int> cp(aaa);
	show_array(cp);
	try
	{
		std::cout << aaa[27] << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
