/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:59:43 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 08:54:22 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen(dst);
	while (dst[i] && i < size)
		i++;
	if (i == size)
		return (size + ft_strlen(src));
	while (src[j] && (i + (j + 1) < size))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (len + ft_strlen(src));
}

// #include <stdio.h>
// #include <bsd/string.h>
// int main(void)
// {
// 	char	src[] = "lorem ipsum dolor sit amet";
// 	char	tp[10]  = "a";
// 	char	dst[10] = "a";
// 	size_t aaa = ft_strlcat(dst, src, 9);
// 	size_t bbb = strlcat(tp, src, 9);
// 	printf("orig\t:\t%ld\t%s\nft\t:\t%ld\t%s\n", bbb, tp, aaa, dst);
// 	return (0);
// }