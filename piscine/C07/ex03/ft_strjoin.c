/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:06:28 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/31 14:28:40 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char	*strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		i++;
	}
	return (i);
}

int	ft_total(char **strs, int size)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (i < size)
	{
		ft_strlen(strs[i]);
		total = total + ft_strlen(strs[i]);
		i++;
	}
	return (total);
}

char	*ft_strcat(char *dest, char *src)
{
	int				cursor;
	unsigned int	len;

	cursor = 0;
	len = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[cursor] != '\0')
	{
		dest[len + cursor] = src[cursor];
		cursor++;
	}
	dest[len + cursor] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*return_string;
	int		total;
	int		i;
	int		pos;

	pos = 0;
	total = 0;
	i = 0;
	if (size == 0)
	{
		return_string = malloc(sizeof(char) * 1);
		return_string = NULL;
		return (return_string);
	}
	total = ft_total(strs, size);
	return_string = malloc(sizeof(char) * (total
				+ (ft_strlen(sep) * (size - 1))) + 1);
	while (i < size)
	{
		return_string = ft_strcat(return_string, strs[i]);
		if (i < size - 1)
			return_string = ft_strcat(return_string, sep);
		i++;
	}
	return (return_string);
}
/* VERIF */
// int	main(void)
// {
// 	// MAIN
// 	char	*strs[] = {"SomeStr1ng", "Separate", "bY", "underScore"};
// 	//char	*strs[] = {""};
// 	char	*sep = "-";
// 	int	size = 4;
// 	int	i = 0;

// 	char *string = ft_strjoin(size, strs, sep);
// 	printf("Sep = \"%s\" ; nbwd = %d\nStrs orig : ", sep, size);
// 	while (i < 4)
// 	{
// 		printf("\"%s\", ", strs[i]);
// 		i++;
// 	}
// 	printf("; addrs = \"%p\"\nStrs return = \"%s\" ; ",strs, string);
// 	printf("addrs = \"%p\"", string);
// 	free(string);
// 	return (0);
// }