/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 08:31:58 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/22 11:50:47 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	cursor;
	int	i;

	i = argc - 1;
	cursor = 0;
	while (i > 0)
	{
		while (argv[i][cursor] != '\0')
		{
			write(1, &argv[i][cursor], 1);
			cursor++;
		}
		cursor = 0;
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
