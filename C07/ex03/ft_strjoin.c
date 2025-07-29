/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:06:28 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/28 15:52:42 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int		cursor;
	int		len;

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

int	ft_count_total(char **strs, int size)
{
	int	total;
	int	i;

	i = 0;
	total = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	return (total);
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
	if (size <= 0)
	{
		return_string = malloc(sizeof(char));
		return_string[0] = '\0';
		return (return_string);
	}
	total = ft_count_total(strs, size);
	printf("%d\n", total);
	return_string = malloc(sizeof(char) * (total + (ft_strlen(sep) * (size - 1))) + 1);
	while (i < size)
	{
		return_string = ft_strcat(return_string, strs[i]);
		if (i < size - 1)
			return_string = ft_strcat(return_string, sep);
		i++;
	}
	return (return_string);
}

int	main(void)
{
	char	*strs[] = {"SomeStr1ng", "Separate", "bY", "SOME", "underScore"};
	char	*sep = "-_-";
	int	size = 5;

	char *string = ft_strjoin(size, strs, sep);
	printf("%s", string);
	free(string);
	return (0);
}

