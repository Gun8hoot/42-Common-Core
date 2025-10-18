/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:34:44 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/18 15:46:01 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while ((((char *)s1)[i] || ((char *)s2)[i]) && i < n)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
		{
			return (((char *)s1)[i] - ((char *)s2)[i]);
		}
		i++;
	}
	return (0);
}

int main(void)
{
	int i;
	char	arr[65] = "asdasda";
	char	test[65] = "dsad";
	char	aaa[64];
	char	bbb[64];
	i = 0;
	int	yy = memcmp(bbb, test, 9 + 1);
	printf("%d ; %d\n", ft_memcmp(test, arr, 9), memcmp(test, arr, 9));
}
