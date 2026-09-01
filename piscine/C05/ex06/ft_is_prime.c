/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:44:52 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/30 11:28:32 by nclavel          ###   ########.fr       */
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
/* VERIFIER */
// int	main(void)
// {
// 	//	MAIN
// 	int	nb = 1;

// 	while (nb < 100)
// 	{
// 		if (ft_is_prime(nb) == 1)
// 			printf("%d is prime\n", nb);
// 		nb++;
// 	}

// }