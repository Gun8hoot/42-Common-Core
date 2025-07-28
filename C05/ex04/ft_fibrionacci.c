/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibrionacci.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:06:07 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/22 09:26:53 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

/*
int	main(void)
{
	int	nb = 30;
	int	i = 0;
	while (i <= nb)
	{
		printf("nth : %d ; fibonacci : %d\n" , i, ft_fibonacci(i));
		i++;
	}
	return (0);
}
*/
