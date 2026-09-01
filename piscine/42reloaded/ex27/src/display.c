#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void display(int fd)
{
    char buffer[999999];
    int sz;
    int i;

    i= 0;
    sz = read(fd, buffer, 999999);
    while (i < sz)
    {
        ft_putchar(buffer[i]);
        i++;
    }
}