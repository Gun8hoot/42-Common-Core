/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:44:48 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/30 11:29:30 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (nb <= 1)
		return (0);
	while (i <= nb)
	{
		if ((nb % i) == 0)
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	return (0);
}

int	ft_find_next_prime(int nb)
{
	int	found;

	found = 0;
	while (found != 1)
	{
		if (ft_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
}
/* VERIFIER */
// int	main(void)
// {
// 	int	nb = 1;
// 	while (nb <= 100)
// 	{
// 		printf("Prime number %d >= %d\n", nb, ft_find_next_prime(nb));
// 		nb++;
// 	}
// 	return (0);
// }