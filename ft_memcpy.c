/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:40:51 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/15 09:09:47 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

// int main()
// {
//     char arr[] = "Hellozww";
//     const goofy = strlen(arr);
// 	char arrr2[goofy];
//     char *ret;
//     int i = 0;
//     ret = ft_memcpy(arrr2, arr, goofy);
//     while (i < goofy)
//     {
//         printf("%c\n", arrr2[i]);
//         i++;
//     }
//     return (0);
// }