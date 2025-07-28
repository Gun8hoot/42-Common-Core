/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:08:07 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/11 07:52:53 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_first_section(char a, char b)
{
	a++;
	b++;
}

void	ft_second_section(char c, char d)
{
	ft_putchar(c);
	ft_putchar(d);
	c++;
	d++;

}

void	ft_print_comb2(void) 
{
	char	a;
	char	b;

	a = '0';
	b = '0';
	ft_second_section(c, d);

	while (a <= '9' && b <= '9')
	{	
		while (c <= '9' && d <= '9')
		{
			ft_second_section(c, d);
			if (d <= 9) 
			{
				d++;	
			}
			else (c <= 9)
			
		}
		ft_first_section(a, b);
	}

}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
