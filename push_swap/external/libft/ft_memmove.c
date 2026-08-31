/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:00:28 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/28 09:53:08 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((char *)dest == NULL && (const char *)src == NULL)
		return (NULL);
	if ((const char *)src > (char *)dest)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((const char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
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
