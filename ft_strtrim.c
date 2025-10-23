/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:30:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/22 16:41:31 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(const char s, const char *set)
{
	int	i;
	int goofy;

	i = 0;
	goofy = 0;
	while (set[i])
	{
		if (s == set[i])
		{
			goofy++;
			break ;
		}
		i++;
	}
	if (goofy > 0)
		return (1);
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(s1);
	if (!s1 && !set)
		return (NULL);
	while (s1[i] && ft_isset(s1[i], set) != 0)
		i++;
	while (ft_isset(s1[k - 1], set) != 0)
		k--;
	arr = malloc(sizeof(char) * (k - i) + 1);
	if (!arr)
		return (NULL);
	k--;
	while (j < k - i +1)
	{
		arr[j] = s1[i + j];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

// int	main(void)
// {
// 	char *arr = "";
// 	char *set = "";
// 	// char *arr = "sdsg";
// 	// char *set = "g";
// 	char *str = ft_strtrim(arr, set);
// 	printf("%s\n", str);
// 	free(str);
// //	free(str);
// 	// char *str = "ashkdas===string";
// 	// for (int i = 0; i < ft_strlen(str); i++)
// 	// {
// 	// 	printf("%d\n", ft_isset("===", &((char*)str)[i]));
// 	// }
// 	return (0);
// }