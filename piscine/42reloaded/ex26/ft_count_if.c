
#include <stdio.h>

int count(char *elements)
{
    int nb;

    nb = 0;
    if (elements[0] == 0)
        return (0);
    while (elements[nb])
    {
        nb++;
    }
    if (nb > 0)
        return (1);
}

int ft_count_if(char **tab, int (*f)(char*))
{
    int i;
    int j;
    int goofy;

    i = 0;
    j = 0;
    while (i < 3)
    {
        goofy = f(tab[i]);
        if (goofy == 1)
            j++;
        else if (goofy == 0)
            break;
        i++;
    }
    printf("%d\n", j);
    return (j);
}
#include <stdlib.h>

int main(void)
{
    char *arr[] = {"Nb of element", "b", "GOFFY", "\0"};
    ft_count_if(arr, &count);
    return(0);
}
