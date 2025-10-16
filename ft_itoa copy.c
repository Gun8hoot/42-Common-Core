/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:32:36 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/16 16:37:24 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_countnb(int nb)
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

static int	ft_isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static char	*ft_put_and_revers(int n, size_t len)
{
	
}

char *ft_itoa(int n)
{
	size_t	len;
	char	*arr;
	
	len = ft_countnb(n);
	size_t	aaa = len;
	arr = malloc(sizeof(char) * len + ft_isneg(n) + 1);
	if (arr == NULL)
		return (NULL);
	if (ft_isneg(n) == 1)
	{
		arr[0] = '-';
		n = -n;
	}
	else
		len--;
	if (n == 0)
		arr[len++] = '0';
	while (n != 0)
	{
		arr[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	arr[aaa + 1] = '\0';
	return (arr);
}


int main(void)
{
	int nb  = -4;
	printf("%s", ft_itoa(nb));
	return (0);
}