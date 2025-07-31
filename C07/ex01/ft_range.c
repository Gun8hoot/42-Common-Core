/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:01:39 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/31 14:28:53 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * (max - min));
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
/* VERIF */
// #include <stdio.h>
// int	main(void)
// {
// 	int min = -5;
// 	int max = 9;
// 	int *arr = ft_range(min, max);
// 	int i = 0;
// 	printf("addr ; %p\n", arr);
// 	while (i < max-min)
// 	{
// 		printf("%d, ", arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }