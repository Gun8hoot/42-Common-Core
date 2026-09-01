/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:03:57 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/30 11:28:26 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	res;
	int	num;

	num = 1;
	res = 0;
	if (nb == 0)
		return (0);
	else if (nb == 1)
		return (1);
	while (num < nb)
	{
		res = num * num;
		if (res == nb)
			return (num);
		num++;
	}
	return (0);
}
/* VERIFIER */
// int	main(void)
// {	
// 	printf("--- PERFERCT SQUARE ---\n");
// 	printf("sqrt ; %d\n", ft_sqrt(1));
// 	printf("sqrt ; %d\n", ft_sqrt(4));
// 	printf("sqrt ; %d\n", ft_sqrt(9));
// 	printf("sqrt ; %d\n", ft_sqrt(16));
// 	printf("sqrt ; %d\n", ft_sqrt(25));
// 	printf("sqrt ; %d\n", ft_sqrt(36));
// 	printf("sqrt ; %d\n", ft_sqrt(49));
// 	printf("sqrt ; %d\n", ft_sqrt(64));
// 	printf("sqrt ; %d\n", ft_sqrt(81));
// 	printf("sqrt ; %d\n", ft_sqrt(100));
// 	printf("sqrt ; %d\n", ft_sqrt(121));
// 	printf("\n--- NON PERFERCT SQUARE ---\n");
// 	printf("sqrt ; %d\n", ft_sqrt(-1));
// 	printf("sqrt ; %d\n", ft_sqrt(0));
// 	printf("sqrt ; %d\n", ft_sqrt(26));
// 	printf("sqrt ; %d\n", ft_sqrt(86));
// 	printf("sqrt ; %d\n", ft_sqrt(532));
// 	printf("sqrt ; %d\n", ft_sqrt(86));
// 	printf("sqrt ; %d\n", ft_sqrt(24));
// 	printf("sqrt ; %d\n", ft_sqrt(96));
// 	printf("sqrt ; %d\n", ft_sqrt(-324));
// 	printf("sqrt ; %d\n", ft_sqrt(55));
// 	printf("sqrt ; %d\n", ft_sqrt(719));
// 	printf("sqrt ; %d\n", ft_sqrt(43));
// 	return (0);
// }
