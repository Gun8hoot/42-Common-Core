/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:40:51 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 08:30:18 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}

// #include <string.h>
// int main()
// {
//     char dest[] = "assjdnsakdbsahkdsbajd";
//     char dest2[] = "assjdnsakdbsahkdsbajd";
// 	char *src = "put in dst";
// 	char *src2 = "put in dst";
// 	int n = 11;
// 	ft_memcpy(dest, src, n);
// 	memcpy(dest2, src2, n);
//     printf("%s\n%s\n", dest, dest2);
//     return (0);
// }