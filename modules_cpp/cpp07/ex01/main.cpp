#include "iter.hpp"
#include <cstring>
#include <iostream>
#include <string>

// Function taking non-const reference – modifies the element
void toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

// Function taking const reference – does not modify
void printChar(const char &c)
{
	std::cout << c;
}

// Function template – can be instantiated as the third parameter
template <typename T>
void printElement(const T &x)
{
	std::cout << x << " ";
}

int main(void)
{
	// --- Test with non-const reference function ---
	{
		std::cout << "-- NON-CONST REFERENCE --" << std::endl;
		char arr[] = "A string to pUt tO UPPer";
		std::size_t len = std::strlen(arr);

		std::cout << "Before : " << arr << std::endl;
		::iter(arr, len, toUpper);
		std::cout << "After  : " << arr << std::endl;
	}

	std::cout << std::endl;

	// --- Test with const reference function ---
	{
		std::cout << "-- CONST REFERENCE --" << std::endl;
		char arr[] = "SEconde string To PUt to U9per.... U";
		std::size_t len = std::strlen(arr);

		std::cout << "Before : " << arr << std::endl;
		std::cout << "After  : ";
		::iter(arr, len, printChar);
		std::cout << std::endl;
	}

	std::cout << std::endl;

	// --- Test with an instantiated function template ---
	{
		std::cout << "-- INSTANTIATED FUNCTION TEMPLATE --" << std::endl;
		int numbers[] = {1, 2, 3, 4, 5};
		std::size_t len = sizeof(numbers) / sizeof(numbers[0]);

		::iter(numbers, len, printElement<int>);
		std::cout << std::endl;
	}

	return 0;
}
