/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:59:43 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/15 09:14:57 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	j;

	len = ft_strlen(dst);
	j = 0;
	while ((len + j) < size)
	{
		dst[len + j] = src[j];
		j++;
	}
	if (ft_strlen(src) == len + j)
		dst[len + j] = '\0';
	else
		dst[len + j - 1] = '\0';
	return (len + ft_strlen(src));
}

// #include <stdio.h>
// #include <bsd/string.h>
// int main(void)
// {
// 	char src[] = "Ajoute";
// 	char dst[20] = "ashdsa";
// 	char tmp[20] = "ashdsa";
// 	size_t aaa = ft_strlcat(dst, src, 8);
// 	size_t bbb = strlcat(tmp, src, 8);
// 	printf("%s;%ld\n%s;%ld", dst, aaa, tmp, bbb);
// 	return (0);
// }