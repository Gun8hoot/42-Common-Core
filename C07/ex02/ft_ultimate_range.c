/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:01:39 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/24 09:03:20 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		return (0);
	}
	*range = malloc(4 * (max - min));
	if (range == NULL)
		return (-1);
	while (min + i < max)
	{
		range[0][i] = min + i;
		i++;
	}
	return (max - min);
}
/*
int	main(void)
{
	// xyz
	int min = 5;
	int max = -5;
	int *range = NULL;

	ft_ultimate_range(&range, min, max);
	if (range != NULL)
	{
		free(range);
	}
	return (0);
}
*/
