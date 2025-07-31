/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaudich <egaudich@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:32:35 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/12 17:06:12 by egaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	start(int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar('A');
		else if (i == x && x > 1)
		{
			ft_putchar('C');
		}
		else if (i != x && x > 1)
			ft_putchar('B');
		i++;
	}
	ft_putchar('\n');
}

void	middle(int x)
{
	int	j;

	j = 1;
	while (j <= x)
	{
		if (j == 1)
			ft_putchar('B');
		else if (j == x && x > 1)
		{
			ft_putchar('B');
		}
		else if (j != x && x > 1)
			ft_putchar(' ');
		j++;
	}
	ft_putchar('\n');
}

void	end(int x, int y)
{
	int	i;

	i = 1;
	if (y > 1)
	{
		while (i <= x)
		{
			if (i == 1)
				ft_putchar('C');
			else if (i == x && x > 1)
			{
				ft_putchar('A');
			}
			else if (i != x && x > 1)
				ft_putchar('B');
			i++;
		}
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (x < 0 || y < 0)
	{
		write(1, "Vous devez mettre des nombres positifs.", 39);
	}
	else
	{
		start(x);
		while (i < y - 2)
		{
			middle(x);
			i++;
		}
		end(x, y);
	}
}
