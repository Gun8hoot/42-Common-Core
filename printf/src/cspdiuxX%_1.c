/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspdiuxX%_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:47:04 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/31 16:23:15 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_putnbr(long nb)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		i++;
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

size_t	ft_pointer(void *ptr)
{
	size_t		size;
	long	cst;

	cst = (unsigned long)ptr;
	size = 0;
	if (ptr == NULL)
		size += ft_putstr("(nil)");
	else
	{
		size += ft_putstr("0x");
		while (cst !=  0)
		{
			cst /= 10;
		}
	}
	return (size);
}

size_t ft_ulhex(unsigned long nb, char *base)
{
	size_t i;

	i = 0;
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