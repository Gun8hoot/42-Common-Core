/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:44:52 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/18 15:37:31 by nclavel          ###   ########.fr       */
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
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	while (i < start)
	{
		printf("Skipping %c\n", s[i]);
		i++;
	}
	while (j < len)
	{
		printf("Putting %c\n", s[i]);
		printf("Sub %c\n", str[j]);
		str[j] = s[i + j];
		j++;
	}
	return (str);
}

// #include <stdio.h>
// #include <string.h>
// int main() {    
//     char *s = "Findersss";
//     char *sub;

// 	sub = ft_substr(s, 3, 4);

//     printf("%s\n", sub);
// 	free(sub);
//     return (0);
// }