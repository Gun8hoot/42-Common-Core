/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:54:52 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/31 14:26:48 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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
/* VERIF */
// #include <stdio.h>
// int	main(void)
// {
// 	char	*str = "Some string to copy";
// 	char	*copy = ft_strdup(str);
// 	char	*ocopy = strdup(str);

// 	if (copy != NULL && ocopy != NULL)
// 	{
// 		printf("copy ; \"%s\"\nocopy ; \"%s\"\n", copy, ocopy);
// 		printf("comp : %d", strcmp(copy, ocopy));
// 		free(copy);
// 		free(ocopy);
// 	}
// 	return (0);
// }