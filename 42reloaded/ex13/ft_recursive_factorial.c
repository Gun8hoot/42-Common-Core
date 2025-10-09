#include <stdio.h>

int ft_recursive_factorial(int nb)
{
    if (nb == 0)
        return (1);
    else if (nb > 0)
    {
        nb = nb * ft_recursive_factorial(nb - 1);
        return (nb);
    }
    return (0);
}

int main(void)
{
    printf("%d\n", ft_recursive_factorial(5));
}