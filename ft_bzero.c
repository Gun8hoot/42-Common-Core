/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:38:23 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/15 09:07:36 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = '\0';
}

// int main()
// {
//     char arr[] = "Hellozww";
//     int i = 0;
//     ft_bzero(arr, 5);
//     while (i < 8)
//     {
//         printf("%c", arr[i]);
//         i++;
//     }
//     return (0);
// }