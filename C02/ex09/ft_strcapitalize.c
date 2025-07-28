/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:14:56 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/20 16:18:10 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32;
		}
		else if (str[i - 1] == ' ' || str[i - 1] == '+' || str[i - 1] == '-')
		{
			str[i] -= 32;
		}
		else if (i != 0 && (str[i] >= 'A' && str[i] <= 'Z'))
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	//char str[] = "hi, how are you? 42words forty-two; fifty+and+one";
// 	char str[] = "   HELLO";
// 	printf("Original string ; \"%s\"\n", str);
// 	printf("Capitalized string ; \"%s\"", ft_strcapitalize(str));
// 	return (0);
// }
