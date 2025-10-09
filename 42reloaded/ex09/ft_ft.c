#include <stdio.h>

void ft_ft(int *nbr)
{
    *nbr = 42;
}

int main(void)
{
    int ptr = 0;
    ft_ft(&ptr);
    printf("%d\n", ptr);
}