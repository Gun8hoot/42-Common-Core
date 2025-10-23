/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:12:32 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/23 16:53:14 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char *res;

	res = (unsigned char *)s;

	i = 0;
	while (n > 0)
	{
		if (*res == (unsigned char)c)
			return ((void *)res);
		res++;
		n--;
	}
	if (c == '\0' && n > 0)
		return ((void *)&res[ft_strlen((char *)s)]);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char *src = "/|\x12\xff\x09\x42\2002\42|\\";
//  	int size = 10;
// 	char c = ft_memchr(src, '\200', size);
// 	printf("%c\n", c);
// }