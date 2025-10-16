/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:50:58 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/16 15:31:37 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (!(i < 0))
	{
		if (s[i] == c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}

// int main()
// {
// 	char str[] = "String qui contient un mots particulier";

// 	printf("%s\n", ft_strrchr(str, 'c'));
//     return 0;
// }