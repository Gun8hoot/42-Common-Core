
# include "ScalarConverter.hpp"

#include <string>
#include <iostream>

// static char getChar(const std::string &literal)
// {
// 	try
// 	{
// 		unsigned char	c = std::stoi(literal);
// 	}
// 	return ();
// }

void	ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
		return;
	if (literal == "nan")
	{
		std::cout	<< "char: Non displayable\n"
							<< "int: impossible\n"
							<< "float: nanf\n"
							<< "double: nan \n";
		return;
	}
	else if (literal == "+inf" || literal == "inf" || literal == "+inff")
	{
		std::cout	<< "char: Non displayable\n"
							<< "int: infinit\n"
							<< "float: infinit\n"
							<< "double: infinit\n";
		return;
	}
}
