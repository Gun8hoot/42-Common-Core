/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 09:32:41 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/30 11:04:29 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb - 1;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	while (i > 0)
	{
		nb = nb * i;
		i--;
	}
	return (nb);
}
/* VERIFIER */
// int	main(void)
// {
// 	// MAIN
// 	int	nb = -10;
// 	while (nb < 12)
// 	{
// 		printf("Factoriel de %d = %d\n", nb, ft_iterative_factorial(nb));
// 		nb++;
// 	}
// 	// MAX 12 apres ca rentre plus dans les int
// 	return (0);
// }