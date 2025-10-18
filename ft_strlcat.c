/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:59:43 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/18 16:38:15 by nclavel          ###   ########.fr       */
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
// int main(int argc, char	**argv)
// {
// 	char src[] = "Ajoute";
// 	char dst[20] = "ashdsa";
// 	char tmp[20] = "ashdsa";
// 	int	jjj = 10;
// 	printf("%d\n", jjj);
// 	size_t aaa = ft_strlcat(dst, src, jjj);
// 	size_t bbb = strlcat(tmp, src, jjj);
// 	printf("%s;%ld\n%s;%ld", dst, aaa, tmp, bbb);
// 	return (0);
// }