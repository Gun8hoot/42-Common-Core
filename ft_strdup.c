/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:39:14 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/18 15:52:33 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int main(int argc, char **argv)
// {
// 	char *str1 = argv[1];
// 	char *str2;

// 	if (argc == 1)
// 		return (1);
// 	str2 = ft_strdup(str1);
// 	printf("%s\n", str2);
// 	free(str2);
// 	return (0);
// }