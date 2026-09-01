#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *ft_range(int min, int max)
{
    int *arr;
    int i;

    arr = malloc(sizeof(int) * (max - min));
    i = 0;

    if (min > max)
        return (NULL);
    while (i < max - min)
    {
        arr[i] = min + i;
        i++;
    }
    return (arr);
}

int main()
{
    int i = 0;
    int *arr;

    arr = ft_range(25, 50);
    while (i < 25)
    {
        printf("%d\n", arr[i]);
        i++;
    }
    return(0);
}