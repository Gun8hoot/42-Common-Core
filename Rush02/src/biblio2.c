/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biblio2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:30:49 by memillet          #+#    #+#             */
/*   Updated: 2025/07/27 23:29:49 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "basic.h"
#include "numbdict.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
	{
		i++;
	}
	dest = malloc(i * sizeof(char));
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_strcat(char **dest, char **src)
{
	int	i;
	int	j;
	int	jcrochet;

	jcrochet = 0;
	i = 0;
	j = 0;
	while (dest[jcrochet][i] != '\0')
		i++;
	jcrochet++;
	i = 0;
	while (src[j] != NULL)
	{
		while (src[j][i])
		{
			dest[jcrochet][i] = src[j][i];
			i++;
		}
		i = 0;
		jcrochet ++;
		j++;
	}
	dest[jcrochet] = NULL;
	return (dest);
}
