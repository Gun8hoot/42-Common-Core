/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:32:36 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/15 17:47:25 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_countnb(int nb)
{
	int c;
	int tmp;

	tmp = nb;
	c = 0;
	if (nb == 0)
		c++;
	while (tmp != 0)
	{
		tmp /= 10;
		c++;
	}
	return (c);
}

char *ft_swap_arr(char *arr, int len)
{
	int i;

	i = 0;
	return (arr);
}

char *ft_itoa(int n)
{
	size_t	len;
	char *arr;
	int	i;

	i = 0;
	len = ft_countnb(n);
	if ((arr = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	if (n < 0)
	{
		arr[0] = '-';
	}
	if (n == 0)
		arr[i++] = '0';
	while (n != 0)
	{
		arr[i++] = (n % 10) + 48;
		n /= 10;
	}
	arr[i] = '\0';
    printf("%s\n", arr);
	return (arr);
}


int main(void)
{
	printf("%s", ft_itoa(-123));
	return (0);
}