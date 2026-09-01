#include <unistd.h>
#include <fcntl.h>
#include "lib/main.h"

int main(int argc, char **argv)
{
    int fd;

    fd = 0;
    if (check(argc) == 1)
        return (1);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        write(1, "Cannot read file.", 18);
        return (1);
    }
    display(fd);
    close(fd);
    return (0);
}
