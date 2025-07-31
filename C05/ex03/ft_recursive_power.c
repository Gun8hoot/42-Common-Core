/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:48:48 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/31 07:39:37 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if ((nb == 0 && power == 0) || power == 0)
		return (1);
	else if (power < 0 || nb == 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}
/* VERIFIER */
// #include <math.h>
// int	main(void)
// {
// 	// MAIN
// 	printf("%d^%d = %d\n", 5, 4, ft_recursive_power(5, 4));
// 	printf("%d^%d = %d\n", 5, 5, ft_recursive_power(5, 5));
// 	printf("%d^%d = %d\n", 10, 2, ft_recursive_power(10, 2));
// 	printf("%d^%d = %d\n", -5, 4, ft_recursive_power(-5, 4));
// 	printf("%d^%d = %d\n", 5, 1, ft_recursive_power(5, 1));
// 	printf("%d^%d = %d\n", 1, 5, ft_recursive_power(1, 5));
// 	printf("%d^%d = %d\n", 10, 5, ft_recursive_power(10, 5));
// 	printf("%d^%d = %d\n", 264, 0, ft_recursive_power(264, 0));
// 	printf("%d^%d = %d\n", 5, -4, ft_recursive_power(5, -4));
// 	printf("%d^%d = %d\n", 591, 4, ft_recursive_power(591, 4));
// 	printf("%d^%d = %d\n", 0, 0, ft_recursive_power(0, 0));
// 	printf("%d^%d = %d\n", 5, 0, ft_recursive_power(5, 0));
// 	printf("%d^%d = %d\n", 4565, 0, ft_recursive_power(4565, 0));
// 	printf("%d^%d = %d\n", 3, 4, ft_recursive_power(3, 4));
// 	printf("%d^%d = %d\n", 0, 5, ft_recursive_power(0, 5));
// 	return (0);
// }