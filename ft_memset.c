/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:31:48 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/17 13:15:26 by nclavel          ###   ########.fr       */
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
//     char arr[] = "Hellozww";
//     char *ret;
//     int i = 0;
//     ret = ft_memset(arr, 'c', 5);
//     //ret = memset(arr, 'c', sizeof(int) * 5);
//     while (i < 8)
//     {
//         printf("%c\n", ret[i]);
//         i++;
//     }
//     return (0);
// }