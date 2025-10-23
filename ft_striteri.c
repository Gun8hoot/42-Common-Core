/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:22:51 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/20 15:54:49 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void ft_ft_toupper(unsigned int i , char *c)
// {
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 48;
// }

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{

		f(i, &((char *)s)[i]);
		i++;
	}
}

// int	main(void)
// {
// 	char *str;
	
// 	str = "Met Tous EN MAJ";
// 	ft_striteri(str, ft_ft_toupper);
// 	printf("%s\n", str);
// 	return (0);
// }