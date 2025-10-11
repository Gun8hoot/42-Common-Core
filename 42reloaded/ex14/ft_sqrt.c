#include <stdio.h>

int ft_sqrt(int nb)
{
    int res = 0;
    int i   = 0;

    while (i < 10)
    {
        res = i * i;
        if (res == nb)
            return (i);
        i++;
    }
    
    return (0);
    
}

int main(void)
{
    printf("%d\n", ft_sqrt(9));
    return(0);
}