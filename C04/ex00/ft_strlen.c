/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:19:04 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/23 14:38:04 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	str[128] = "abcdefg";

// 	printf("%s ; %d\n", str, ft_strlen(str));
// 	printf("strlen ; %lu", strlen(str));
// 	return (0);
// }