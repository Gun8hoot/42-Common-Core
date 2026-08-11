
#include "iter.hpp"
#include <cstring>
#include <iostream>

int	toup(char &c)
{
	if ((c >= 'a' && c <= 'z'))
		c = c - 32;
	return (c);
}

int main(void)
{
	char	arr[] = "A string to pUt tO UPPer";
	std::size_t	len = std::strlen(arr);
	// int &ptr = toup

	::iter(arr, len, toup);
	std::cout << arr << std::endl;
}
