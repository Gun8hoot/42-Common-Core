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

#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str1 = "RTES";
    char *str2 = "HQD";
    printf("a : %d  | b : %d\n", ft_strcmp(str1, str2), strcmp(str1, str2));
}