#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

char    *ft_strcpy(char *dst, char *src)
{
    int i;
    i = 0;

    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

int ft_strcmp(char *str1, char *str2)
{
    int i;

    i = 0;
    while (str1[i] || str2[i])
    {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    char *order[256];
    
    i = 1;
    j = 0;
    if (argc == 1)
        return (1);
    
    while (i < argc)
    {
        if (ft_strcmp(argv[i], argv[i+1]) > 0)
        
    }
    return (0);
}