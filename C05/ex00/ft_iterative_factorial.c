/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 09:32:41 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/22 09:43:35 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb - 1;
	while (i > 0)
	{
		nb = nb * i;
		i--;
	}
	return (nb);
}

// int	main(void)
// {
//	ft_iterative_factorial(5);
//	printf("%d", ft_iterative_factorial(5));
//	return (0);
// }
