/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:32:36 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 07:53:30 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	countnb(int nb)
{
	int	c;
	int	cp;

	cp = nb;
	c = 0;
	if (nb == 0)
		c++;
	if (nb < 0)
		c++;
	while (cp != 0)
	{
		cp /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*arr;
	long	cp;

	cp = (long)n;
	len = countnb(cp);
	arr = malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	arr[len] = '\0';
	if (cp == 0)
		arr[0] = '0';
	else if (cp < 0)
	{
		arr[0] = '-';
		cp = -cp;
	}
	while (cp > 0)
	{
		len--;
		arr[len] = (cp % 10) + '0';
		cp /= 10;
	}
	return (arr);
}

// #include <string.h>
// int main(void)
// {
// 	char *arr = ft_itoa(-2147483648);
// 	printf("%s\n", arr);
// 	return (0);
// }