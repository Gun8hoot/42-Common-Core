/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:11:18 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/17 16:44:38 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	str[i + 1] += '\0';
	return (str);
}

// int	main(void)
// {
// 	char str[] = "STrinGS";
// 	printf("\"%s\", ", str);
// 	printf("%s\n", ft_strlowcase(str));
// 	return (0);
// }
