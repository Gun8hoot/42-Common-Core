/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 08:57:05 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/17 16:47:00 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// void	ft_putstr_non_printable(char *str)
// {
// 	int	i;
// 	int	j;
// 	char	tmp[256];

// 	i = 0;
// 	j = 0;
// 	while (str[i])
// 	{
// 		if (str[i] <= '\037')
// 		{
// 			while ()
// 			tmp[i] = '\\';
// 			write(1, &tmp[i], 1);
// 		}
// 		else
// 		{
// 			write(1, &str[i], 1);
// 		}
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	char	*str;
// 	str = "Hello\nHow are you?";
// 	ft_putstr_non_printable(str);
// }
