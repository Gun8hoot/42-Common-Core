#include <stdio.h>

int ft_sqrt(int nb)
{
    int res = nb;
    int i   = 0;

    while (res > nb)
    {
        res = i * nb;
        if (res == nb)
            return (i);
        i++;
    }
    
    return (0);
    
}

int main(void)
{
    printf("%d\n", ft_sqrt(5));
}