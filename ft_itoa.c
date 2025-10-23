/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:32:36 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/21 17:42:09 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_countnb(int nb)
{
	int	c;
	int	tmp;

	tmp = nb;
	c = 0;
	if (nb == 0)
		c++;
	if (nb < 0)
		c++;
	while (tmp != 0)
	{
		tmp /= 10;
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
	len = ft_countnb(cp);
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
		arr[len] = (cp % 10) + 48;
		cp /= 10;
	}
	return (arr);
}
// #include <string.h>
// int main(void)
// {
// 	char *mine = ft_itoa(0);
// 	printf("%s\n", mine);
// 	return (0);
// }