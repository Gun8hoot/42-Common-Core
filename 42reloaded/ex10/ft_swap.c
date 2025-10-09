void ft_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

#include <stdio.h>
int main(void)
{
    int a = 42;
    int b = 1;
    ft_swap(&a, &b);
    printf("%d | %d\n", a, b);
}