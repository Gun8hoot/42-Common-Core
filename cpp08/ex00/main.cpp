
#include "easyfind.hpp"

#include <exception>
#include <iostream>
#include <iterator>

#include <deque>
#include <list>
#include <vector>

#define GREEN "\x1b[0;32m"
#define RED "\x1b[0;31m"
#define RESET "\x1b[0m"

int main(void)
{
	std::cout << GREEN << " // VALID TEST \\\\ " << RESET << std::endl;
	{
		std::cout << GREEN << "-- SEARCH ON A VECTOR --" << RESET << std::endl;
		std::vector<int> aaa;

		int search = 44;
		aaa.push_back(25);
		aaa.push_back(6);
		aaa.push_back(search);
		try
		{
			std::vector<int>::iterator pos = easyfind(aaa, search);
			std::cout << search << " was found : " << *pos << std::endl;
		}
		catch (std::exception & ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << GREEN << "-- SEARCH ON A LIST --" << RESET << std::endl;
		std::list<int> aaa;

		int search = 44;
		aaa.push_back(25);
		aaa.push_back(6);
		aaa.push_back(search);
		try
		{
			std::list<int>::iterator pos = easyfind(aaa, search);
			std::cout << search << " was found : " << *pos << std::endl;
		}
		catch (std::exception & ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << GREEN << "-- SEARCH ON A DEQUE --" << RESET << std::endl;
		std::deque<int> aaa;

		int search = 44;
		aaa.push_back(25);
		aaa.push_back(6);
		aaa.push_back(search);
		try
		{
			std::deque<int>::iterator pos = easyfind(aaa, search);
			std::cout << search << " was found : " << *pos << std::endl;
		}
		catch (std::exception & ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}

	std::cout << std::endl;

	std::cout << RED << " // INVALID TEST \\\\" << std::endl;

	{
		std::cout << RED << "-- GIVE A NON INT CONTAINER --" << RESET << std::endl;
		std::vector<char> aaa;

		int search = 'z';
		aaa.push_back('a');
		aaa.push_back('4');
		aaa.push_back(search);
		try
		{
			std::vector<char>::iterator pos = easyfind(aaa, search);
			std::cout << search << " was found : " << *pos << std::endl;
		}
		catch (std::exception & ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << RED << "-- SEARCH A NUMBER WHO ARE NOT ON THE CONTAINER --" << RESET << std::endl;
		std::vector<int> aaa;

		int search = 777;
		aaa.push_back(1);
		aaa.push_back(2);
		aaa.push_back(3);
		try
		{
			std::vector<int>::iterator pos = easyfind(aaa, search);
			std::cout << search << " was found : " << *pos << std::endl;
		}
		catch (std::exception & ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
}
