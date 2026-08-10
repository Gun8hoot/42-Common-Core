
# include "ScalarConverter.hpp"

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>

// static std::size_t	count_nb(const std::string &lit)
// {
// 	std::size_t	i = 0;
// 	std::size_t	c = 0;

// 	while (i < lit.length())
// 	{
// 		if (lit[i] >= '0' && lit[i] <= '9')
// 			c++;
// 		i++;
// 	}
// 	return (c);
// }

static void printChar(const std::string &literal)
{
	long val = std::strtol(literal.c_str(), NULL, 10);

	std::cout << "char: ";
	if (errno == ERANGE || val > std::numeric_limits<char>::max() || val < 0)
	{
		std::cout << "Impossible" << std::endl;
	}
	else if (val <=0x1F)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << static_cast<char>(val) << "\'" << std::endl;
}

static void printInt(const std::string &literal)
{
	long val = std::strtol(literal.c_str(), NULL, 10);

	std::cout << "int: ";
	if (errno == ERANGE || val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
	{
		std::cout << "Impossible" << std::endl;
	}
	else
		std::cout << static_cast<int>(val) << std::endl;
}

static void	printFloat(const std::string &literal)
{
	float val = std::strtof(literal.c_str(), NULL);
	std::size_t	dotPos = 0;
	int			precision;

	std::cout << "float: ";
	if (errno == ERANGE)
		std::cout << "Impossible" << std::endl;
	else
	{
		dotPos = literal.find(".");
		if (dotPos == std::string::npos)
			std::cout << std::fixed << std::setprecision(1) << val << "f" << std::endl;
		else
		{
			precision = literal.find_last_of("f") == std::string::npos ? literal.length() : literal.find_last_of("f");
			precision = precision - dotPos - 1;
			std::cout << std::fixed << std::setprecision(precision > std::numeric_limits<float>::digits10 ? std::numeric_limits<float>::digits10 : precision) << val << "f" << std::endl;
		}
	}
}

static void	printDouble(const std::string &literal)
{
	double val = std::strtod(literal.c_str(), NULL);
	std::size_t	dotPos = 0;
	int			precision;

	std::cout << "double: ";
	if (errno == ERANGE)
		std::cout << "Impossible" << std::endl;
	else
	{
		dotPos = literal.find(".");
		if (dotPos == std::string::npos)
			std::cout << std::fixed << std::setprecision(1) << val << "f" << std::endl;
		else
		{
			precision = literal.find_last_of("f") == std::string::npos ? literal.length() : literal.find_last_of("f");
			std::cout << std::fixed << std::setprecision(precision - dotPos - 1) << val << std::endl;
		}
	}
}

static bool	checkLiteral(const std::string &literal)
{
	std::size_t	lit_size = literal.length();
	bool		has_dot = false;
	bool		has_f = false;

	for (std::size_t i = 0; i < lit_size; i++)
	{
		/* HANDLE MINUS */
		if (i == 0 && literal[i] == '-')
			continue;
		/* CHECK FOR INVALID CHARACTER */
		if (!(literal[i] >= '0' && literal[i] <= '9')
			&& literal[i] != 'f'
			&& literal[i] != '.')
			return (true);

		/* HANdLE DOT */
		if (literal[i] == '.')
		{
			if (has_dot || i == lit_size - 1)
				return (true);
			has_dot = true;
			continue;
		}

		/* HANDLE F AT END */
		if (literal[i] == 'f')
		{
			if (has_f || i != lit_size - 1)
				return (true);
			has_f = true;
			continue;
		}
	}
	return (false);
}

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
	}
	else if (literal == "+inf" || literal == "inf" || literal == "+inff" || literal == "inff")
	{
		std::cout	<< "char: Non displayable\n"
					<< "int: infinit\n"
					<< "float: infinit\n"
					<< "double: infinit\n";
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout	<< "char: Non displayable\n"
					<< "int: -infinit\n"
					<< "float: -infinit\n"
					<< "double: -infinit\n";
	}
	else if (checkLiteral(literal))
		std::cout << "[!] \"" << literal << "\" is invalid!" << std::endl;
	else
	{
		printChar(literal);
		printInt(literal);
		printFloat(literal);
		printDouble(literal);
	}
}
