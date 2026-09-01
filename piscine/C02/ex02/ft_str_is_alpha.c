/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:06:01 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/20 16:19:55 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	if (i == 0)
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (ft_check_empty(str) == 1)
	{
		return (1);
	}
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			i++;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
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
// 	printf("\"%s\", %d\n", "abcdefghijkl", ft_str_is_alpha("abcdefghijkl"));
// 	printf("\"%s\", %d\n", "STRING", ft_str_is_alpha("STRING"));
// 	printf("\"%s\", %d\n", "Str!ng", ft_str_is_alpha("Str!ng"));
// 	printf("\"%s\", %d\n", "", ft_str_is_alpha(""));
// 	printf("\"%s\", %d\n", "[]1!", ft_str_is_alpha("[]1!"));
// 	printf("\"%s\", %d\n", "Stri1g", ft_str_is_alpha("Stri1g"));
// }