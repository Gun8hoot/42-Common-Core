/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 08:31:58 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/29 08:47:11 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	cursor;

	cursor = 0;
	while (cursor < n && (s1[cursor] || s1[cursor]))
	{
		if (s1[cursor] != s2[cursor])
		{
			break ;
		}
		cursor++;
	}
	return (s1[cursor] - s2[cursor]);
}

char	*ft_strcat(char *dest, char *src)
{
	int	cursor;
	int	len;

	cursor = 0;
	len = 0;
	while (dest[cursor] != '\0')
	{
		cursor++;
	}
	while (src[len] != '\0')
	{
		dest[cursor + len] = src[len];
		len++;
	}
	dest[cursor + len] = '\0';
	return (dest);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(int argc, char **argv)
{
	int	i;
	char	**tmp;

	tmp = NULL;
	i = 1;
	while (i <= argc)
	{
		if (ft_strncmp(argv[i], argv[i + 1], 1) > 0)
			ft_strcat(tmp[i], argv[i + 1]);
		else
			ft_strcat(tmp[i], argv[i]);
		i++;
	}
	return (0);
}
