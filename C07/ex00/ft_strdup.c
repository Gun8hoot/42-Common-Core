/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:54:52 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/28 14:19:26 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*copy;

	copy = NULL;
	copy = malloc(1 * ft_strlen(src));
	if (copy == NULL)
	{
		return (NULL);
	}
	ft_strcpy(copy, src);
	return (copy);
}
/*
#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	char	*str = "Copie moi ca stp ! Tiee un tigre";
	char	*copy = ft_strdup(str);
	char	*ocopy = strdup(str);

	if (copy != NULL)
	{
//		printf("copy funct ; %s\ncopy  ; %s", copy, ocopy);
		free(copy);
		free(ocopy);
	}
	return (0);
}
*/
