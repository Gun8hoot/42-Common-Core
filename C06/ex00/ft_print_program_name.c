/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 08:20:42 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/18 08:29:34 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	cursor;

	cursor = 0;
	if (argc > 1)
	{
		return (1);
	}
	while (argv[0][cursor] != '\0')
	{
		write(1, &argv[0][cursor], 1);
		cursor++;
	}
	write(1, "\n", 1);
	return (0);
}
