#include <unistd.h>

int check(int ac)
{
    if (ac < 2)
    {
        write(1, "File name missing.", 19);
        return (1);
    }
    else if (ac > 2)
    {
        write(1, "Too many arguments.", 20);
        return (1);
    }
    return (0);
}