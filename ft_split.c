/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:29:36 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 13:14:46 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static void	*ft_free_alem(char **arr, int j)
{
	j -= 1;
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
	return (NULL);
}

static	int	ft_countword(const char *str, const char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		count++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

static size_t	ft_lenword(const char *str, const char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != c)
	{
		if (str[i] == c)
		{
			i++;
		}
		while (str[i] != c && str[i])
		{
			i++;
			count++;
		}
	}
	return (count);
}

static	char	*ft_dup(const char *s, const char c)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_lenword(s, c);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[j] = ft_dup(&s[i], c);
			if (arr[j] == NULL)
				return (ft_free_alem(arr, j));
			i += ft_lenword(&s[i], c);
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
	arr[j] = NULL;
	return (arr);
}

// int main(void)
// {
// 	char	*str = " Hello! World !       ";
// 	char sep = ' ';
// 	char **splited = ft_split(str, sep);
// 	for (int z = 0; splited[z]; z++)
// 		printf("%s\n", splited[z]);
// 	ft_free_alem(splited, ft_countword(str, sep));
// 	return (0);
// }