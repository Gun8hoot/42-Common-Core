/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:33:56 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/17 07:58:52 by nclavel          ###   ########.fr       */
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
/*
#include <stdio.h>
int	main(void)
{
	char	*str;
	int	nmb;
	
	str = "Hello World!";
	nmb = ft_strlen(str);
	printf("The len for the string \"%s\" is %d\n", str, nmb);
}
*/