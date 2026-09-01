/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:21:25 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/17 07:58:51 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp_div;
	int	tmp_mod;

	tmp_div = *a / *b;
	tmp_mod = *a % *b;
	*a = tmp_div;
	*b = tmp_mod;
}
/*
#include <stdio.h>
int	main(void)
{
	int a = 42;
	int b = 39;
	int *ptr1 = &a;
	int *ptr2 = &b;
	ft_ultimate_div_mod(ptr1, ptr2);
	printf("mod = %d, div = %d", *ptr2, *ptr1);
	return (0);
}
*/