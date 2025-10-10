#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int check(int ac)
{
    if (ac == 1)
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    
    i = 1;
    j = 0;
    if (argc == 1)
        return (1);
    
    while (i < argc)
    {
        while (argv[i][j])
        {
            ft_putchar(argv[i][j]);
            j++;
        }
        ft_putchar('\n');
        j = 0;
        i++;
    }
    return (0);
}