/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:30:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 09:10:16 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(const char s, const char *set)
{
	int	i;
	int	charisset;

	i = 0;
	charisset = 0;
	while (set[i])
	{
		if (s == set[i])
		{
			charisset++;
			break ;
		}
		i++;
	}
	if (charisset > 0)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	i;
	size_t	k;

	i = 0;
	k = ft_strlen(s1);
	if (!s1 && !set)
		return (NULL);
	while (s1[i] && ft_isset(s1[i], set) != 0)
		i++;
	while (ft_isset(s1[k - 1], set) != 0)
		k--;
	arr = ft_substr(s1, i, k - i);
	return (arr);
}

// int	main(void)
// {
// 	char *s1 = "\t               tri\tmed\t";
//  	char *str = ft_strtrim(s1, " \n\t");
// 	printf("\"%s\"\n", str);
// 	free(str);
// 	return (0);
// }