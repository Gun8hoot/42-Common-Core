/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:54:30 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/17 07:58:46 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp[128];
	int	current_pos;

	current_pos = 0;
	while (current_pos < size)
	{
		tmp[current_pos] = 0;
		tmp[current_pos] += tab[(size - 1) - current_pos];
		current_pos++;
	}
	current_pos = 0;
	while (current_pos < size)
	{
		tab[current_pos] = tmp[current_pos];
		current_pos++;
	}
}
/*
#include <stdio.h>
void	ft_print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);	// La fonction servait juste
		if (i != size - 1)		// pour la correction
		{
			printf(", ");
		}
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int	tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	size;

	size = 10;
	printf("Original array : ");
	ft_print_tab(tab, size);
	ft_rev_int_tab(tab, size);
	printf("\nReversed array : ");
	ft_print_tab(tab, size);
	return (0);
}
*/