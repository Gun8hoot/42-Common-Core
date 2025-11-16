/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:44:52 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 13:12:07 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	j = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup (""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (j < len && s[start + j])
	{
		str[j] = s[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

// #include <stdio.h>
// #include <string.h>
// int main() {    
//     char *sub;
// 	sub = ft_substr("hola", 0, 4);
//     printf("%s\n", sub);
// 	free(sub);
// }