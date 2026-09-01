/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biblio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 05:05:16 by lbardet-          #+#    #+#             */
/*   Updated: 2025/07/27 23:29:38 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "basic.h"
#include "numbdict.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char	*ft_strndup(char *src, int n)
{
	char	*dup;
	int		i;

	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strcpy(char *dest, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
