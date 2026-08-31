/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:47:04 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/05 14:52:14 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		i += ft_putstr("(null)");
		return (i);
	}
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
		ft_putchar(nb + '0');
		i++;
	}
	return (i);
}

size_t	ft_pointer(void *ptr)
{
	size_t		size;

	size = 0;
	if (ptr == NULL)
		size += ft_putstr("(nil)");
	else
	{
		size += ft_putstr("0x");
		size += ft_ulhex((unsigned long)ptr, "0123456789abcdef");
	}
	return (size);
}

size_t	ft_ulhex(unsigned long nb, char *base)
{
	size_t	i;

	i = 0;
	if (nb >= 16)
		i += ft_ulhex(nb / 16, base);
	i += ft_putchar(base[nb % 16]);
	return (i);
}
