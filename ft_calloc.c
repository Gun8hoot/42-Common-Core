/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 07:56:42 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/23 15:20:52 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	i;

	i = 0;
	arr = malloc(size * nmemb);
	if (!arr)
		return (NULL);
	if (size == 0)
		return (arr);
	while (i < (size * nmemb))
	{
		((char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}

// int main(void)
// {
// 	char *arr;
// 	char *zzz;

// 	arr = ft_calloc(8539, sizeof(int));
// 	//ft_print_tab(arr, 10);
// 	for (int i = 0; i < 8539; i++)
// 	{
// 		if (arr[i] != 0)
// 			printf("pb at %d\n", i);
// 	}
// 	//printf("%s\n", arr);
// 	free(arr);
// 	return (0);
// }
