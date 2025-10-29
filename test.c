#include "lib/printf.h"
#include <stdio.h>
int main(void)
{
	char *d = "asgdcsahfgcdsghad";
	// int d = 2147483647;

	char *cc = "%s";

	printf("\n%d\n", ft_printf(cc, d));
	printf("\n%d\n", printf(cc, d));
	
	return (0);
}

//alias tstpf="make re; cc ./test.c ./ft_printf.a"