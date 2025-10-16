/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:29:36 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/15 15:25:39 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_countword(const char *str, const char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count + 1);
}

int	finder(char *s, unsigned int a)
{
	int c;

	c = 0;
	while 
}

char **ft_split(char const *s, char c)
{
	char **arr;
	int i;
	int	j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if ((arr = malloc(sizeof(char) * ft_countword(s, c))) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] != c)
		{
			if ((arr[j] = malloc(sizeof(char) * )) == NULL);
				return (NULL);
			arr[j][k] = s[i++];
			k++;
		}

		i++;
		j++;
	}
	return (arr);
}

int main(void)
{
	char arr[] = "Split-this-thing";
	printf("%d\n", ft_countword(arr, '-'));
	// char **splited = ft_split(arr, '-');
	// for (int i = 0; i < 3; i++)
	// 	printf("%s\n", splited[i]);
	return (0);
}