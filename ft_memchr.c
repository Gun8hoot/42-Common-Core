/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:12:32 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/20 17:35:45 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char str[] = "asdcacsdsad";
// 	char let = 'c';
// 	if (ft_memchr(str, let, 2))
//     	printf("%c is in the str\n", let);
// 	else
//     	printf("%c is not in the str\n", let);
//     return 0;
// }