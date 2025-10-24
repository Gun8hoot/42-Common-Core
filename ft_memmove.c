/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:00:28 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 13:16:57 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n--)
			tmp_dest[n] = tmp_src[n];
	}
	else
		return (ft_memcpy(tmp_dest, tmp_src, n));
	return (tmp_dest);
}

// #include <string.h>
// int main(void)
// {
// 	char	src[] = "kkhbfkahbd";
// 	char	dest[] = "some str on the dest";
// 	char	dest2[] = "some str on the dest";
// 	int i = 8;
// 	ft_memmove(dest, src, i);
// 	memmove(dest2, src, i);
// 	printf("%s ; \n%s", dest, dest2);
// }
