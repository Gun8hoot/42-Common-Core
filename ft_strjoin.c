/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:06:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/16 15:36:48 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	lens1;
	size_t	lens2;
	char	*str;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * lens1 + lens2 + 1);
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < lens2)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

// int main(void)
// {
// 	char *str;

// 	str = ft_strjoin("mots1", "mots2");
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
