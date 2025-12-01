/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspdiuxX%_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 07:56:18 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/04 09:45:52 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_printf.h"
#include <stdio.h>

size_t	ft_hex(unsigned int nb, char *base)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		i += ft_hex(nb, base);
	}
	if (nb >= 16)
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

size_t	ft_unsputnbr(unsigned int nb)
{
	size_t	i;

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
