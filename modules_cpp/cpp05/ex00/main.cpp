
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Bureaucrat user("user", 75);
        std::cout << user << std::endl;

        Bureaucrat user2("user2", 44);
        std::cout << user2 << std::endl;

        // Constructor: grade too high
        try {
            Bureaucrat invalid("invalid", 0);
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }

        // Constructor: grade too low
        try {
            Bureaucrat invalid("invalid", 151);
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }

        // incrementGrade on highest grade
        try {
            Bureaucrat b("b", 1);
            b.incrementGrade();
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }

        // decrementGrade on lowest grade
        try {
            Bureaucrat b("b", 150);
            b.decrementGrade();
        } catch (std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }

        // Normal increment / decrement
        Bureaucrat b("b", 75);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
    }
    catch (std::exception &exc)
    {
        std::cout << exc.what() << std::endl;
    }

    return 0;
}
