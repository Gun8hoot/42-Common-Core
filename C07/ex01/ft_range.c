/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:01:39 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/28 14:21:10 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	*range(int min, int max)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(4 * (max - min));
	if (arr == NULL || min >= max)
	{
		return (NULL);
	}
	while (min + i < max)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>
int	main(void)
{
	int min = -5;
	int max = 5;
	int *arr = range(min, max);
	int i = 0;

	while (i < max-min)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	free(arr);
	return (0);
}*/
