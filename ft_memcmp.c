/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:34:44 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 08:23:46 by nclavel          ###   ########.fr       */
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
// 	// char *s1 = "strbienlongueetbiendifferente";
// 	char *s1 = "str2";
// 	char *s2 = "str2";
// 	i = 9;
// 	printf("%d ; %d\n", ft_memcmp(s1, s2, i), memcmp(s1, s2, i));
// }
