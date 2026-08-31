#include "lib/printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	char *d = "asgdcsahfgcdsghad";
	char *N = NULL;
	// int d = 2147483647;

	char *cc = "%s";

	printf("\n# STRING #\n");
	printf("\n%d\n", ft_printf("%s", "askdhbasvhdjavsdjsavd"));
	printf("\n%d\n", printf("%s", "askdhbasvhdjavsdjsavd"));

	printf("\n# INT #\n");
	printf("\n%d\n", ft_printf("%i", 46597845));
	printf("\n%d\n", printf("%i", 46597845));
	printf("\n%d\n", ft_printf("%i", -46597845));
	printf("\n%d\n", printf("%i", -46597845));
	printf("\n%d\n", ft_printf("%i", -2147483648));
	printf("\n%d\n", printf("%i", -2147483648));
	printf("\n%d\n", ft_printf("%i", 2147483647));
	printf("\n%d\n", printf("%i", 2147483647));
	printf("\n%d\n", ft_printf("%i", 0));
	printf("\n%d\n", printf("%i", 0));

	printf("\n# UNSIGNED INT #\n");
	printf("\n%d\n", ft_printf("%u", 4294967295));
	printf("\n%d\n", printf("%u", 4294967295));
	printf("\n%d\n", ft_printf("%u", 0));
	printf("\n%d\n", printf("%u", 0));
	printf("\n%d\n", ft_printf("%u", -4));
	printf("\n%d\n", printf("%u", -4));
	printf("\n%d\n", ft_printf("%u", 4654));
	printf("\n%d\n", printf("%u", 4654));

	printf("\n# CHAR #\n");
	printf("\n%d\n", ft_printf("%c", 'c'));
	printf("\n%d\n", printf("%c", 'c'));
	printf("\n%d\n", ft_printf("%c", 48));
	printf("\n%d\n", printf("%c", 48));
	printf("\n%d\n", ft_printf("%c", '\106'));
	printf("\n%d\n", printf("%c", '\106'));
	printf("\n%d\n", ft_printf("%c", NULL));
	printf("\n%d\n", printf("%c", NULL));

	printf("\n# POINTER ADDR #\n");
	printf("\n%d\n", ft_printf("%p", N));
	printf("\n%d\n", printf("%p", N));
	printf("\n%d\n", ft_printf("%p", d));
	printf("\n%d\n", printf("%p", d));
	printf("\n%d\n", ft_printf("%p", ULONG_MAX));
	printf("\n%d\n", printf("%p", ULONG_MAX));
	printf("\n%d\n", ft_printf("%p", LONG_MIN));
	printf("\n%d\n", printf("%p", LONG_MIN));
	printf("\n%d\n", ft_printf("%p", LONG_MAX));
	printf("\n%d\n", printf("%p", LONG_MAX));

	printf("\n# HEXA (low) #\n");
	printf("\n%d\n", ft_printf("%x", 444));
	printf("\n%d\n", printf("%x", 444));
	printf("\n%d\n", ft_printf("%x", 2147483647));
	printf("\n%d\n", printf("%x", 2147483647));
	printf("\n%d\n", ft_printf("%x", -2147483647));
	printf("\n%d\n", printf("%x", -2147483647));
	printf("\n%d\n", ft_printf("%x", 15));
	printf("\n%d\n", printf("%x", 15));

	printf("\n# HEXA (up) #\n");
	printf("\n%d\n", ft_printf("%X", 444));
	printf("\n%d\n", printf("%X", 444));
	printf("\n%d\n", ft_printf("%X", 2147483647));
	printf("\n%d\n", printf("%X", 2147483647));
	printf("\n%d\n", ft_printf("%X", -2147483647));
	printf("\n%d\n", printf("%X", -2147483647));
	printf("\n%d\n", ft_printf("%X", 15));
	printf("\n%d\n", printf("%X", 15));

	printf("\n# AIO #\n");
	printf("\n%d\n", ft_printf("J'ecrit une str %s, %d, %p, %X, ashgdasfdafsdytfdays, %c", "qui est giga longue", 12, N, 495));
	printf("\n%d\n", printf("J'ecrit une str %s, %d, %p, %X, ashgdasfdafsdytfdays, %c", "qui est giga longue", 12, N, 495));
	return (0);
}

//alias tstpf="make re; cc ./test.c ./ft_printf.a"
