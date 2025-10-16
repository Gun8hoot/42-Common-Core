/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:30:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/15 16:14:41 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s1[i + j] == set[j])
			j++;
		if (j == ft_strlen(set))
		{
			j = 0;
			if ((arr = malloc(sizeof(char) * (ft_strlen(s1) - i) + 1)) == NULL)
				return (NULL);
			while (s1[i + j])
			{
				arr[j] = s1[i + j + 1];
				j++;
			}
			return (arr);
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char *str = ft_strtrim("cat:platipus", ":");
	printf("%s\n", str);
	free(str);
	return (0);
}