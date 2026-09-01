#include <string.h>
#include <unistd.h>
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

char **sort(char **orig, int size)
{
    int i = 0;
    int j = 0;
    char *sort[size];

    while (sort[i])
    {
        if (strcmp(orig[i], orig[i - 1]) < 0)
        {
            strcpy(sort[i], orig[i - 1]);
            i = 0;
        }
        else 
        {
            strcpy(sort[i], orig[i]);
        }
        i++;
    }
    i = 0;

    while (sort[i]);
    {
        while (sort[i][j])
        {
            ft_putchar(sort[i][j]);
            j++;
        }
        ft_putchar('\n');
        j = 0;
        i++;
    }
}

int main(void)
{
    char *arr[] = {"ccc", "bbb", "aaa"};
    sort(arr, 3);
    return (0);
}