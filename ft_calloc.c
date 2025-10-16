/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 07:56:42 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/15 15:32:28 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	i;

	i = 0;
	if (!size || !nmemb)
		return (NULL);
	arr = malloc(nmemb * size + 1);
	if (arr == NULL)
		return (NULL);
	while (i < nmemb)
	{
		((char *)arr)[i] = '1';
		i++;
	}
	return (arr);
}

// void    ft_print_tab(int *tab, int size)
// {
//     int    i;

//     i = 0;
//     while (i < size)
//     {
//         printf("%d", tab[i]);
//         if (i != size - 1)
//         {
//             printf(", ");
//         }
//         i++;
//     }
//     printf("\n");
// }

int main(void)
{
	char *arr;

	arr = ft_calloc(10, sizeof(char));
	//ft_print_tab(arr, 10);
	//for (int i = 0; i < 10; i++)
	//	printf("%d\n", arr[i]);
	printf("%s\n", arr);
	free(arr);
	return (0);
}
