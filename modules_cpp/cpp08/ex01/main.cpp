#include "Span.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main(void)
{
	std::cout << "// SUBJECT TEST \\\\" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "shortest = " << sp.shortestSpan() << std::endl;
		std::cout << "longest  = " << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl << "// addNumbers (iterator range) TEST \\\\" << std::endl;
	{
		std::vector<int> src;
		for (int i = 0; i < 10000; ++i)
			src.push_back(i * 2);

		Span sp(10000);
		sp.addNumbers(src.begin(), src.end());

		std::cout << "shortest = " << sp.shortestSpan() << std::endl;
		std::cout << "longest  = " << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl << "// OVERFLOW TEST \\\\" << std::endl;
	{
		Span sp(5);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(5);

		try
		{
			sp.addNumber(6);
		}
		catch (std::exception &ex)
		{
			std::cout << "Err : " << ex.what() << std::endl;
		}
	}

	std::cout << std::endl << "// NOT ENOUGH NUMBERS TEST \\\\" << std::endl;
	{
		Span sp(5);
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception &ex)
		{
			std::cout << "Err : " << ex.what() << std::endl;
		}
	}

	return 0;
}
