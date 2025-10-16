/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:15:41 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/15 09:15:46 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char dst[999] = "akjsdsads";
// 	char aaa[999] = "akjsdsads";
// 	char *src = "copythisstrplz";
// 	size_t ff = ft_strlcpy(dst, src, 8);
// 	size_t zz = strlcpy(aaa, src, 8);
// 	printf("%ld > %s\n", ff, dst);
// 	printf("%ld > %s\n", zz, aaa);
// }