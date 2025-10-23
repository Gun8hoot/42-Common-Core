/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:44:52 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/23 09:08:07 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	
	if (start >= ft_strlen(s))
		ft_strdup("");
	while (i < start && start < ft_strlen(s))
		i++;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);	
	while (j < len && start < ft_strlen(s))
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

#include <stdio.h>
#include <string.h>
int main() {    
    char *s = "01234";
    char *sub;

	sub = ft_substr("hola", 4, 1);
    printf("%s\n", sub);
	free(sub);
	// sub = ft_substr("hola", 0, -1);
    // printf("%s\n", sub);
	// free(sub);
	// sub = ft_substr("hola", -1, -1);
    // printf("%s\n", sub);
	// free(sub);
	// sub = ft_substr("hola", 0, 4);
    // printf("%s\n", sub);
	// free(sub);
	// sub = ft_substr("hola", 0, 5);
    // printf("%s\n", sub);
	// free(sub);
	// sub = ft_substr("hola", 2, 4);
    // printf("%s\n", sub);
	// free(sub);
	// sub = ft_substr("hola", 0, 1);
    // printf("%s\n", sub);
	// free(sub);
	// sub = ft_substr("hola", 0, 1);
    // printf("%s\n", sub);
	// free(sub);
	// sub = ft_substr("hola", 0, 1);
    // printf("%s\n", sub);
	// free(sub);
	// sub = ft_substr("hola", 0, 1);
    // printf("%s\n", sub);
	// free(sub);
	// sub = ft_substr("hola", 0, 1);
    // printf("%s\n", sub);
	// free(sub);
	// sub = ft_substr("hola", 0, 1);
    // printf("%s\n", sub);
	// free(sub);
	// sub = ft_substr("hola", 0, 1);
    // printf("%s\n", sub);
	// free(sub);
	// sub = ft_substr("hola", 0, 1);
    // printf("%s\n", sub);
	// free(sub);
    return (0);
}