/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:02:26 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/18 15:35:27 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("libft : \"%d\"\norigin : \"%d\"\n\n", ft_atoi("0"), atoi("0"));
	printf("libft : \"%d\"\norigin : \"%d\"\n\n", ft_atoi("256"), atoi("256"));
	printf("libft : \"%d\"\norigin : \"%d\"\n\n", ft_atoi("2147483647"), atoi("2147483647"));
	printf("libft : \"%d\"\norigin : \"%d\"\n\n", ft_atoi(" -2147483648"), atoi(" -2147483648"));
	printf("libft : \"%d\"\norigin : \"%d\"\n\n", ft_atoi("   -1"), atoi("   -1"));
	printf("libft : \"%d\"\norigin : \"%d\"\n\n", ft_atoi("+25"), atoi("+25"));
	printf("libft : \"%d\"\norigin : \"%d\"\n\n", ft_atoi("\03225"), atoi("\03225"));
}