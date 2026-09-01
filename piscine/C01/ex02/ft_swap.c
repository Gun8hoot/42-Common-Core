/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:50:30 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/17 07:58:49 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
#include <stdio.h>
int main(void)
{
	int a;
	int b;

	a = 42;
	b = 24;
	printf("Avant swap : a = %d; b = %d\n", a, b);

	ft_swap(&a, &b);
	printf("Apres swap : a = %d; b = %d", a, b);
}
*/