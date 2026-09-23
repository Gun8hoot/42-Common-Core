
#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <cmath>
#include <iomanip>

static bool isCharLiteral(const std::string &lit)
{
    return lit.length() == 3 && lit[0] == '\'' && lit[2] == '\'';
}

static void printChar(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value)
        || value < std::numeric_limits<char>::min()
        || value > std::numeric_limits<char>::max())
    {
        std::cout << "impossible" << std::endl;
    }
    else if (value < 32 || value > 126)
    {
        std::cout << "Non displayable" << std::endl;
    }
    else
    {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
}

static void printInt(double value)
{
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value)
        || value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << static_cast<int>(value) << std::endl;
    }
}

static void printFloat(double value)
{
    std::cout << "float: ";
    if (std::isnan(value))
    {
        std::cout << "nanf" << std::endl;
        return;
    }
    if (std::isinf(value))
    {
        std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
        return;
    }
    if (value > std::numeric_limits<float>::max()
        || value < -std::numeric_limits<float>::max())
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    float f = static_cast<float>(value);
    if (f == static_cast<int>(f))
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    else
        std::cout << f << "f" << std::endl;
}

static void printDouble(double value)
{
    std::cout << "double: ";
    if (std::isnan(value))
    {
        std::cout << "nan" << std::endl;
        return;
    }
    if (std::isinf(value))
    {
        std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
        return;
    }
    if (value == static_cast<int>(value))
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    else
        std::cout << value << std::endl;
}

static bool isPseudoLiteral(const std::string &lit)
{
    return lit == "nan" || lit == "nanf"
        || lit == "+inf" || lit == "-inf" || lit == "inf"
        || lit == "+inff" || lit == "-inff" || lit == "inff";
}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty())
        return;

    // --- char literal ---
    if (isCharLiteral(literal))
    {
        char c = literal[1];
        printChar(static_cast<double>(c));
        printInt(static_cast<double>(c));
        printFloat(static_cast<double>(c));
        printDouble(static_cast<double>(c));
        return;
    }

    // --- pseudo literals ---
    if (isPseudoLiteral(literal))
    {
        if (literal == "nan" || literal == "nanf")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (literal == "+inf" || literal == "inf"
                 || literal == "+inff" || literal == "inff")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else if (literal == "-inf" || literal == "-inff")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return;
    }

    // --- try int ---
    char *endptr;
    errno = 0;
    long intVal = std::strtol(literal.c_str(), &endptr, 10);
    if (*endptr == '\0' && errno != ERANGE
        && literal.find('.') == std::string::npos
        && literal.find('f') == std::string::npos)
    {
        double value = static_cast<double>(intVal);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }

    // --- try float / double ---
    errno = 0;
    double doubleVal = std::strtod(literal.c_str(), &endptr);
    if (errno == ERANGE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (*endptr == '\0' || (*endptr == 'f' && *(endptr + 1) == '\0'))
    {
        printChar(doubleVal);
        printInt(doubleVal);
        printFloat(doubleVal);
        printDouble(doubleVal);
        return;
    }

    std::cout << "[!] \"" << literal << "\" is invalid!" << std::endl;
}
