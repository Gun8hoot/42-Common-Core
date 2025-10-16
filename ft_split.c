/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:29:36 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/16 15:34:03 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static	int	ft_countword(const char *str, const char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
			i++;
		count++;
	}
	return (count);
}

static	char	*ft_dup(const char *s, const char c)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	if ((str = malloc(sizeof(char) * len + 1)) == NULL);
		return (NULL);
	printf("%ld\n", len);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char **ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((arr = malloc(sizeof(char*) * ft_countword(s, c) + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[j] = ft_dup(&((char*)s)[i], c);
			printf("%c\n", s[i]);
		}
		while (s[i] != c && s[i])
		{
			printf("%c\n", s[i]);
			i++;
		}
		while (s[i] == c && s[i])
		{
			printf("\n%c\n\n", s[i]);
			i++;
		}
		printf("%s", arr[j]);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

void test_free(char **arr)
{
	arr = malloc(sizeof(char*) * 3 + 1);
	for (int i = 0; i < 3; i++)
	{
		arr[i] = malloc(sizeof(char) * 10 + 1);
	}
	arr[0] = "str1\n";
	arr[1] = "str2\n";
	arr[2] = "str3\n";
	for (int i = 0; i < 3; i++)
	{
		printf("%s", arr[i]);
	}
	free(arr);
}

static void	ft_free_alem(char **arr)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int main(void)
{
	//char **arr;
	 char arr[] = "Split-this-Ghing";
	// printf("%s\n%d\n", arr, ft_countword(arr, '-'));
	char **splited = ft_split(arr, '-');
	for (int i = 0; i < 3; i++)
		printf("%s\n", splited[i]);
//	test_free(arr);

	return (0);
}