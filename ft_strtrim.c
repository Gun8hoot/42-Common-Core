/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:30:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/16 16:16:13 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(const char *set, char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(set);
	while (set[i])
	{
		if (s[i] == set[i])
			i++;
		else
			break;
	}
	if (i == len)
		return (1);
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	int	i;
	int	j;

	i = 0;
	j = 0;
	arr = malloc(sizeof(char) * ft_strlen(s1) - (ft_strlen(set) * 2) + 1);
	if (arr == NULL)
		return (NULL);
	while (s1[i])
	{
		if ((ft_isset(set, &((char*)s1)[i])) == 1)
			i += ft_strlen(set);
		while (s1[i])
		{
			if (ft_strlen(&((char*)s1)[i]) - ft_strlen(set) == 0)
				break;
			arr[j] = s1[i];
			i++;
			j++;
		}
	}
	arr[j] = '\0';
	return (arr);
}

int	main(void)
{
	char *str = ft_strtrim("   STR To TRIM   ", "   ");
		printf("%s\n", str);
	free(str);
	// char *str = "ashkdas===string";
	// for (int i = 0; i < ft_strlen(str); i++)
	// {
	// 	printf("%d\n", ft_isset("===", &((char*)str)[i]));
	// }
	return (0);
}