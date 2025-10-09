int ft_strcmp(char *str1, char *str2)
{
    int i;

    i = 0;
    while (str1[i] || str2[i])
    {
        if (str1[i] != str2[i])
            return (str1 - str2);
    }
    return (0);
}
#include <stdio.h>
#include <string.h>
int main(void)
{
    char *str1 = "REGS";
    char *str2 = "TGS";
    printf("a : %d  | b : %d\n", ft_strcmp(str1, str2), strcmp(str1, str2));
}