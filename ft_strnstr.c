/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:39:37 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/15 09:21:12 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

int	ft_islittle(const char *big, const char *little)
{
	size_t	i;

	i = 0;
	while (big[i] == little[i])
		i++;
	if (i == ft_strlen(little))
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (j == ft_strlen(little) - 1)
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
int main(void)
{
	int nb = 40;
	printf("%s ;\n", ft_strnstr("Trouve le mots \"anticonstitutionnellement\" dans cette phrase", "anticonstitutionnellement", nb));
	printf("%s ;\n", strnstr("Trouve le mots \"anticonstitutionnellement\" dans cette phrase", "anticonstitutionnellement", nb));
	return (0);
}