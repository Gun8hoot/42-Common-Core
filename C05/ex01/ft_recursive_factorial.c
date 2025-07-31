/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 09:32:41 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/30 11:04:37 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	else if (nb == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}
/* VERIFIER */
// int	main(void)
// {
// 	int	nb = 1;
// 	while (nb < 12)
// 	{
// 		printf("Factoriel de %d = %d\n", nb, ft_recursive_factorial(nb));
// 		nb++;
// 	}
// 	//	MAX 12, Le reste ne rentre pas dans les int
// 	return (0);
// }
