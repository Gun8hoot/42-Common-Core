#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 5; ++i)
    {
        Base *base = generate();
        if (!base)
            continue;

        std::cout << "identify(ptr): ";
        identify(base);
        std::cout << "identify(ref): ";
        identify(*base);

        delete base;
        std::cout << std::endl;
    }
    return 0;
}
