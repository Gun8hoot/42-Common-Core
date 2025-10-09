void    ft_div_mod(int a, int  b, int  *div, int   *mod)
{
    *div = a / b;
    *mod = a % b;
}
// #include <stdio.h>
// int main(void)
// {
//     int a = 5;
//     int b = 10;
//     int div, mod = 0;

//     ft_div_mod(a, b, &div, &mod);
//     printf("a = %d, b = %d,  div = %d, mod = %d\n", a, b, div, mod);
// }