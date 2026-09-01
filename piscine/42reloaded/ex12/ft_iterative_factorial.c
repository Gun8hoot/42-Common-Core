#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int i;

    i = nb - 1;
    if (nb == 0)
        return (1);
    if (nb > 0)
    {
        while (i > 0)
        {
            printf("%d = %d * %d = ", nb, nb, i - 1);
            nb = nb * i;
            printf("%d\n", nb);
            i--;
        }
        return (nb);
    }
    return (0);
}

int main(void)
{
    printf("%d\n", ft_iterative_factorial(5));
}
