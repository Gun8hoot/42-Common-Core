/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:01:39 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/31 14:27:21 by nclavel          ###   ########.fr       */
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
		range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (range == NULL)
		return (-1);
	while (min + i < max)
	{
		range[0][i] = min + i;
		i++;
	}
	return (max - min);
}
/* VERIF */
// int	main(void)
// {
// 	int min = -4;
// 	int max = 5;
// 	int *range = NULL;
// 	int i = 0;

// 	printf("size = %d\n", ft_ultimate_range(&range, min, max));
// 	if (range != NULL)
// 	{
// 		while (i < max-min)
// 		{
// 			printf("%d, ", range[i]);
// 			i++;
// 		}
// 	}
// 	free(range);
// 	return (0);
// }