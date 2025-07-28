/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:06:01 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/20 16:20:08 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (ft_check_empty(str) == 1)
	{
		return (1);
	}
	while (str[i])
	{
		if (str[i] >= '\141' && str[i] <= '\172')
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
// 	printf("\"%s\", %d\n", "string", ft_str_is_lowercase("string"));
// 	printf("\"%s\", %d\n", "stringS", ft_str_is_lowercase("stringS"));
// 	printf("\"%s\", %d\n", "1234q", ft_str_is_lowercase("1234q"));
// 	printf("\"%s\", %d\n", "", ft_str_is_lowercase(""));
// 	printf("\"%s\", %d\n", "fff", ft_str_is_lowercase("fff"));
// 	printf("\"%s\", %d\n", "z", ft_str_is_lowercase("z"));
// 	printf("\"%s\", %d\n", "a444", ft_str_is_lowercase("a444"));
// }
