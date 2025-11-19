/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:15:41 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 08:55:21 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <bsd/string.h>
// int main(void)
// {
// 	char dst[999] = "AAAAAAAAAAAAAAAAAAAA";
// 	char goofy[999] = "AAAAAAAAAAAAAAAAAAAA";
// 	char *src = "lorem ipsum dolor sit amet";
// 	int byt = 0;
// 	size_t ff = ft_strlcpy(dst, src, byt);
// 	size_t zz = strlcpy(goofy, src, byt);
// 	printf("mine : %ld > %s\n", ff, dst);
// 	printf("orig : %ld > %s\n", zz, goofy);
// }
