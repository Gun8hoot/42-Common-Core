
#include "Span.hpp"

#include <iostream>

int	main(void)
{
	std::cout << "// VALID TEST \\\\" << std::endl;
	{
    Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

		std::cout << "longest = " << sp.longestSpan() << std::endl;
		std::cout << "shortest = " << sp.shortestSpan() << std::endl;
	}

}
