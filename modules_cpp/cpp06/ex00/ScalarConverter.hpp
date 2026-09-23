
#pragma once

#include <string>

class ScalarConverter
{
private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &cpy);
    ScalarConverter &operator=(const ScalarConverter &cpy);
    ~ScalarConverter(void);

public:
    static void convert(const std::string &literal);
};
