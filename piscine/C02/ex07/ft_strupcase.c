/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:37:40 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/17 16:49:18 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	str[i + 1] += '\0';
	return (str);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = "sTRing";
// 	printf("\"%s\", ", str);
// 	printf("%s\n", ft_strupcase(str));
// 	return (0);
// }
