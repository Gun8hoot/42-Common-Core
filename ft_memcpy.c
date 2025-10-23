/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:40:51 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/23 17:08:57 by nclavel          ###   ########.fr       */
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

// int main()
// {
//     char arr[] = "Hellozww";
//     const size_t goofy = ft_strlen(arr);
// 	char arrr2[goofy];
//     char *ret;
// 	ret = malloc(1000000);
//     int i = 0;
//     ret = ft_memcpy("s", "asdas", 14);
//     printf("%s\n", ret);
// 	free(ret);
//     return (0);
// }