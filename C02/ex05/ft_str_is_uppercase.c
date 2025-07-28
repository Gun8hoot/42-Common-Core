/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:54:43 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/19 17:13:01 by nclavel          ###   ########.fr       */
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

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (ft_check_empty(str) == 1)
	{
		return (1);
	}
	while (str[i])
	{
		if (str[i] >= '\101' && str[i] <= '\132')
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
// 	printf("\"%s\", %d\n", "string", ft_str_is_uppercase("string"));
// 	printf("\"%s\", %d\n", "STRING", ft_str_is_uppercase("STRING"));
// 	printf("\"%s\", %d\n", "1234q", ft_str_is_uppercase("1234q"));
// 	printf("\"%s\", %d\n", "", ft_str_is_uppercase(""));
// 	printf("\"%s\", %d\n", "fff", ft_str_is_uppercase("fff"));
// 	printf("\"%s\", %d\n", "z", ft_str_is_uppercase("z"));
// 	printf("\"%s\", %d\n", "a444", ft_str_is_uppercase("a444"));
// }
