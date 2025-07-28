/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:01:19 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/20 14:01:09 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i])
	{
		if (!(str[i] >= ' ' && str[i] <= 127))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("\"%s\", %d\n", "string", ft_str_is_printable("string"));
// 	printf("\"%s\", %d\n", "STRING", ft_str_is_printable("STRING"));
// 	printf("\"%s\", %d\n", "\\0", ft_str_is_printable("\0"));
// 	printf("\"%s\", %d\n", "", ft_str_is_printable(""));
// 	printf("\"%s\", %d\n", "\\n", ft_str_is_printable("\n"));
// 	printf("\"%s\", %d\n", "\\r", ft_str_is_printable("\r"));
// 	printf("\"%s\", %d\n", "fff", ft_str_is_printable("fff"));
// 	printf("\"%s\", %d\n", "z", ft_str_is_printable("z"));
// 	printf("\"%s\", %d\n", "a444", ft_str_is_printable("a444"));
// }
