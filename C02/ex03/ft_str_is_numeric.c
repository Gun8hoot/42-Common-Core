/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:06:01 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/20 16:20:39 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	if (i == 0)
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (ft_check_empty(str) == 1)
	{
		return (1);
	}
	while (str[i])
	{
		if (str[i] >= '\060' && str[i] <= '\071')
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("\"%s\", %d\n", "Str1ng", ft_str_is_numeric("Str1ng"));
// 	printf("\"%s\", %d\n", "12345", ft_str_is_numeric("12345"));
// 	printf("\"%s\", %d\n", "1234q", ft_str_is_numeric("1234q"));
// 	printf("\"%s\", %d\n", "", ft_str_is_numeric(""));
// 	printf("\"%s\", %d\n", "ASa1234", ft_str_is_numeric("ASa1234"));
// 	printf("\"%s\", %d\n", "444Q", ft_str_is_numeric("444Q"));
// 	printf("\"%s\", %d\n", "a444", ft_str_is_numeric("a444"));
// }
