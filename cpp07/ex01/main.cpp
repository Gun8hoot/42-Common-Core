
#include "iter.hpp"
#include <cstring>
#include <iostream>

void	toup(char &c)
{
	if ((c >= 'a' && c <= 'z'))
		c = c - 32;
}

int main(void)
{
	char	arr[] = "A string to pUt tO UPPer";
	std::size_t	len = std::strlen(arr);

	::iter(arr, len, toup);
	std::cout << arr << std::endl;
}
