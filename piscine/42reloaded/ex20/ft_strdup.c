#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char    *ft_strdup(char *src)
{
    char *dst;
    int i;

    i = 0;
    dst = malloc(sizeof(char) * ft_strlen(src));
    while (src[i])
    {
        dst[i] = src[i];
        i++;   
    }
    dst[i] = '\0';
    return (dst);
}

int main(void)
{
    char *src = "AZE AZE";
    char *dst;

    dst = ft_strdup(src);
    printf("%s\n", dst);
}
