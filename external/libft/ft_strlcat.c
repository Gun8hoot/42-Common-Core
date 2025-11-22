/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:59:43 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/29 14:44:29 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	j = dlen;
	if (size == 0 || size <= dlen)
		return (ft_strlen(src) + size);
	while (src[i] && i < (size - dlen - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int main(void)
// {
// 	size_t nb = 80;
// 	char	src[] = "str qui est pas trop longue";
// 	char	dst[] = "aasds";
// 	char	ssrc[] = "str qui est pas trop longue";
// 	char	odst[]  = "aasds";
// 	size_t	bbb = ft_strlcat(dst, src, nb);
// 	size_t	aaa = strlcat(odst, ssrc, nb);
// 	printf("orig : %ld\t%s\nft   : %ld\t%s\n", aaa, odst, bbb, dst);
// 	return (0);
// }	