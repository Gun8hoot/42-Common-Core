
#pragma once

#include <string>

class ScalarConverter
{
	private:
		// -- CONSTRUCTOR --
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &cpy);
		ScalarConverter	&operator=(const ScalarConverter &cpy);
		~ScalarConverter();

		// -- METHODE --
		static void	convert(const std::string &literal);
};
