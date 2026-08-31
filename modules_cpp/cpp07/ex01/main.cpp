
#include "iter.hpp"
#include <cstring>
#include <iostream>

char	toup(char &c)
{
	if ((c >= 'a' && c <= 'z'))
		c = c - 32;
	return (c);
}

char	c_toup(char &c)
{
	if ((c >= 'a' && c <= 'z'))
		c = c - 32;
	return (c);
}

int main(void)
{
	{
		std::cout << "-- REFERENCE -- " << std::endl;
		char	arr[] = "A string to pUt tO UPPer";
		std::size_t	len = std::strlen(arr);
		char (&ref)(char &) = c_toup;

		std::cout << "[+] Before : " << arr << std::endl;
		::iter(arr, len, ref);
		std::cout << "[+] After : " << arr << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "-- CONST REFERENCE -- " << std::endl;
		char	arr[] = "SEconde string To PUt to U9per.... U";
		std::size_t	len = std::strlen(arr);

		std::cout << "[+] Before : " << arr << std::endl;
		::iter(arr, len, c_toup);
		std::cout << "[+] After : " << arr << std::endl;
	}
}
