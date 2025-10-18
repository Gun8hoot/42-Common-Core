/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:00:28 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/18 14:48:19 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;
	size_t	i;

	i = n - 1;
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	if (ft_strlen(dest) < ft_strlen(src))
		return (ft_memcpy(dest, src, n));
	else
	{
		while (i > 0)
		{
			printf("%ld\n", i);
			tmp_dest[i] = tmp_src[i];
			i--;
		}
		tmp_dest[0] = ((unsigned char *)src)[0];
	}
	return (tmp_dest);
}

int main(int argc, char **argv)
{
	int i;
	char	*src = "strsdsds";
	char	*dest = "aasdsa";
	
	char *tt = ft_memmove(dest, src, 9);
	char *yy = memmove(dest, src, 9);
	i = 0;
	printf("%s ; \n%s", yy, tt);
}
