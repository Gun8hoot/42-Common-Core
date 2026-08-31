/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:12:32 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 13:17:31 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*res;

	res = (unsigned char *)s;
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
// 	char *src = "hsbdasdsbadjshabd";
//  	int size = 47;
// 	char *c = ft_memchr(src, '\0', size);
// 	printf("%s\n", c);
// }