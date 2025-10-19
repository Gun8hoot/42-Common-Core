/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:30:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/18 12:51:10 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(const char *set, const char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(set);
	printf("%s\n", s);
	while (set[i] && s[i] == set[i])
	{
		printf("%c ; %c\n", s[i], set[i]);
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}

static int	ft_setontbegend(char const *s1, char const *set)
{
	size_t	len_set;
	size_t	len_s1;
	size_t	i;
	size_t	c;

	len_set = ft_strlen(set);
	len_s1 = ft_strlen(s1);
	i = 0;
	c = 0;
	while (s1[i])
	{
		if ((i == 0 || i == len_s1 - len_set) 
			&& ft_isset(&((char *)s1)[i], set) == 1)
			c++;
		i++;
	}
	return (c);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	arr = malloc(sizeof(char) * (ft_strlen(s1) - (ft_strlen(set) * ft_setontbegend(s1, set))) + 1);
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

// int	main(void)
// {
// 	char *arr = "===STR To=== TRIM===";
// 	char *set = "===";
// 	char *str = ft_strtrim(arr, set);
// 		printf("%s\n", str);
// 	free(str);
// 	// char *str = "ashkdas===string";
// 	// for (int i = 0; i < ft_strlen(str); i++)
// 	// {
// 	// 	printf("%d\n", ft_isset("===", &((char*)str)[i]));
// 	// }
// 	return (0);
// }