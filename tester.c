/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:02:36 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/18 15:08:27 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	// ATOI
	printf("--- ATOI ---\n");
	printf("libft : %d\norigin : %d\n", ft_atoi("0"), atoi("0"));
	printf("libft : %d\norigin : %d\n", ft_atoi("256"), atoi("256"));
	printf("libft : %d\norigin : %d\n", ft_atoi("2147483647"), atoi("2147483647"));
	printf("libft : %d\norigin : %d\n", ft_atoi("-2147483647"), atoi("-2147483647"));
	printf("libft : %d\norigin : %d\n", ft_atoi("   -1"), atoi("   -1"));
	printf("libft : %d\norigin : %d\n", ft_atoi("+25"), atoi("+25"));
	printf("libft : %d\norigin : %d\n", ft_atoi("0"), atoi("0"));
	return (0);
}