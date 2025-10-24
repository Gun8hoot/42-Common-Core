/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:31:48 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 08:36:16 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i++] = c;
	}
	return (s);
}

// int main()
// {
//     char str[] = "Set C on the area rh";
//     char *ret;
//     int i = 0;
//     ret = ft_memset(str, 'c', 10);
//     //ret = memset(arr, 'c', sizeof(int) * 5);
//     printf("%s\n", ret);
//     return (0);
// }