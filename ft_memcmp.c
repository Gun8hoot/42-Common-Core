/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:34:44 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/22 12:24:18 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	int i;
// 	char *s1 = "\xff\0\0\xaa\0\xde\xffMACOSX\xff";
// 	char *s2 = "\xff\0\0\xaa\0\xde\x00MBS";
// 	char	aaa[64];
// 	char	bbb[64];
// 	i = 0;
// 	printf("%d ; %d\n", ft_memcmp(s1, s2, 9), memcmp(s1, s2, 9));
// }
