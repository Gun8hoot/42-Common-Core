/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 07:46:18 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/03 23:48:36 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_printf.h"
#include <stdio.h>

int	argument(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_unsputnbr(va_arg(arg, int)));
	else if (c == 'x')
		return (ft_hex(va_arg(arg, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_hex(va_arg(arg, int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
		return (ft_pointer(va_arg(arg, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	len_add;
	va_list	list;
	size_t	i;

	i = 0;
	len_add = 0;
	if (str == NULL)
		return (0);
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len_add += argument(str[i + 1], list);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			len_add++;
		}
		i++;
	}
	va_end(list);
	return (len_add);
}
