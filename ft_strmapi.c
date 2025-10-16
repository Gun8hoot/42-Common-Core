/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:39:46 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/16 17:06:21 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char ft_ft_toupper(unsigned int i , char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	while (s[i])
	{
		if (str == NULL)
			return (NULL);
		str[i] = f(1, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	main(void)
{
	char *str;
	
	str = ft_strmapi("Met Tous EN MAJ", ft_ft_toupper);
	printf("%s\n", str);
	free(str);
	return (0);
}