/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:10:47 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/28 10:08:24 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char *str = "string lenght!";
// 	printf("%d ; %d\n", ft_strlen(str), strlen(str));
// 	return (0);
// }