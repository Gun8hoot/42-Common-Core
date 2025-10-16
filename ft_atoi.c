/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:02:26 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/16 16:18:16 by nclavel          ###   ########.fr       */
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
	while (nptr[i] >= 1 && nptr[i] <= ' ')
	{
		i++;
	}
	if (nptr[i] == '-')
	{
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

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// 	// char *nb = "     \t-2147483648";
// 	char *nb = "--5";
// 	int aaa = ft_atoi(nb);
// 	printf("%d ; %d\n", aaa, atoi(nb));
// }