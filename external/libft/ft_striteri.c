/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:22:51 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 13:15:03 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void f(unsigned int i , char *c)
// {
// 	(void)i;
// 	c[0] -= 32;
// }

// int	main(void)
// {
// 	char str[] = "hgasdghd";
// 	ft_striteri(str, &f);
// 	printf("%s\n", str);
// 	return (0);
// }