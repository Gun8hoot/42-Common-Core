/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:48:48 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/22 09:47:23 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = nb;
	if (power < 0)
	{
		return (0);
	}
	else if (nb == 0 && power == 0)
	{
		return (1);
	}
	while (i < power)
	{
		tmp = nb * tmp;
		i++;
	}
	return (tmp);
}
/*
int	main(void)
{
	int nb = 0;
	int power = 0;

	printf("%d^%d = %d\n", nb, power, ft_iterative_power(nb, power));
}
*/
