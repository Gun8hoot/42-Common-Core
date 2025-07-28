/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:03:57 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/22 11:24:34 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	res;
	int	num;
	
	num = 1;
	res = 0;
	if (nb == 0 || nb < 0)
		return (0);
	while (num < nb)
	{
		res = num * num;
		if (res == nb)
			return (num);
		num++;
	}
	return (0);
}


int	main(void)
{
	printf("sqrt ; %d^2\n", ft_sqrt(10));
	return (0);
}
