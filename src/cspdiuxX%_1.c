/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspdiuxX%_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:47:04 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/29 16:10:24 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
	{
		nb = nb + '0';
		write(1, &nb, 1);
		i++;
	}
	return (i);
}

int	ft_pointer(void *ptr)
{
	int		size;
	long	cst;

	cst = (long)ptr;
	size = 0;
	if (ptr == NULL)
		ft_putstr("(nil)");
	else
	{
		size = 2;
		ft_putstr("0x");
		size += ft_hex(cst, "0123456789abcdef");
	}
	return (size);
}
