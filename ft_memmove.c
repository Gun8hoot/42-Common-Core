/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:00:28 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/23 08:30:01 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;
	size_t			i;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	i = n - 1;
	if (!dest && !src)
		return (NULL);
	if (strlen(tmp_dest) < strlen(tmp_src))
	{
		ft_memcpy(tmp_dest, tmp_src, n);
	}
	else
	{
		while (i > 0)
		{
			tmp_dest[i] = tmp_src[i];
			i--;
		}
		tmp_dest[0] = ((unsigned char *)src)[0];
	}
	return (tmp_dest);
}

int main(void)
{
	char	src[] = "strsdsds";
	char	dest[] = "aasdsasa";
	char	goofy[] = "aasdsasa";
	ft_memmove(dest, src, 9);
	memmove(goofy, src, 9);
	printf("%s ; \n%s", dest, goofy);
}
