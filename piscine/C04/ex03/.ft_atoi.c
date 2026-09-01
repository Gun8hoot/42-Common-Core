/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .ft_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:56:04 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/22 08:35:26 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

// norme a faire
int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	res;

	num = 0;
	sign = 1;
	res = 0;
	while (str[num] || (str[num] >= 65 && str[num] <= 122))
	{
		if (str[num] == '-')
			sign = -sign;
		else if (str[num] >= 'A' && str[num] <= 'z')
			break ;
		else if (str[num] == ' ' && str[num] == '/')
			;
		else if (str[num] >= '0' && str[num] <= '9')
			res = res * 10 + (str[num] - 48);
		num++;
	}
	return (sign * res);
}
// #include <stdlib.h>
// int	main(void)
// {
// 	char str[] = "    ---5+--+1234ab567";
// 	//char str[] = "     ----8-+1234ab567";
// 	//char str[] = "";
// 	//char str[] = "-2147483648";
// 	printf("%d\n%d", ft_atoi(str), atoi(str));
// 	return (0);
// }