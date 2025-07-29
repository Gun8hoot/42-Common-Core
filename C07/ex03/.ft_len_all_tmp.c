int     ft_strlen(char  **strs, int size)
{
        int     total;
        int     i;
        int     j;

        j = 0;
        i = 0;
        total = 0;
        while (i < size)
        {
                while (strs[i][j] != '\0')
                {
                        printf("j = %d\n", j);
                        j++;
                }
                printf("i = %d\n", i);
                total = total + j;
                j = 0;
                i++;
        }
        return (total);
}
