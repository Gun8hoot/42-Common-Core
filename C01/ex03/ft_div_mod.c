/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:38:53 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/17 07:58:50 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>
int	main(void)
{
	int	a = 42;
	int	b = 39;
	int	mod;
	int	div;

	printf("Valeur a & b : a = %d; b = %d\n", a, b);
	ft_div_mod(a, b, &mod, &div);
	printf("mod = %d, div = %d\n", mod, div);
	return (0);
}
*/