/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspdiuxX%_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 07:56:18 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/29 13:57:03 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/printf.h"
#include <stdio.h>

// int	ft_hex(int nb, char *base)
// {
// 	int i;
// 	int hex;
// 	char str[100];

// 	i = 0;
// 	if (nb < 0)
// 	{
// 		write(1, "-", 1);
// 		nb = -nb;
// 		i++;
// 	}
// 	while (nb != 0)
// 	{
// 		hex = nb % 16;
// 		str[i] = base[hex];
// 		write(1, &str[i], 1);
// 		nb /= 16;
// 		i++;
// 	}
// 	return (i);
// }

int	ft_hex(unsigned int nb, char *base)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		i += ft_hex(nb, base);
	}
	if (nb > 16)
	{
		i += ft_hex(nb / 16, base);
		i += ft_hex(nb % 16, base);
	}
	else
	{
		ft_putchar(base[nb]);
		i++;
	}
	return (i);
}

int	ft_unsputnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putchar(nb % 10 + '0');
	}
	else
	{
		ft_putchar(nb + '0');
		i++;
	}
	return (i);
}
