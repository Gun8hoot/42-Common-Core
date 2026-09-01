/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:06:07 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/30 11:28:19 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/* VERIFIER */
// #include <stdio.h>
// int	main(void)
// {
// 	// MAIN
// 	int	i = 0;
// 	while (i <= 27)
// 	{
// 		printf("nth : %d ; fibonacci : %d\n" , i, ft_fibonacci(i));
// 		i++;
// 	}
// 	return (0);
// }
