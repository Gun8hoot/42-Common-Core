/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 08:31:58 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/29 12:14:14 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2)
{
	unsigned int	cursor;

	cursor = 0;
	while ((s1[cursor] || s2[cursor]) && cursor < 1)
	{
		if (s1[cursor] != s2[cursor])
		{
			return (s1[cursor] - s2[cursor]);
		}
		cursor++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char		**tmp;

	tmp = NULL;
	i = 1;
	j = 0;
	while (i < argc)
	{
		printf("%d", ft_strncmp(argv[i], argv[i+1]));
		i++;
	}
	return (0);
}
