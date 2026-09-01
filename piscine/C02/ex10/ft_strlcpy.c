/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:28:27 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/20 16:21:20 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://c-for-dummies.com/blog/?p=3873

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
// #include <stdio.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 	char	*src;
// 	char	dest[128];
// 	char	original_dest[128];
// 	unsigned int	size;

// 	src = "Hello World!";
// 	size = 5;
// 	unsigned int buffer = ft_strlcpy(dest, src, size);
// 	printf("\"%s\" ; \"%s\", %d, %d\n", src, dest, buffer, ft_strlen(dest));
// 	printf("\"%s\" ; ", src);
// 	printf("\"%s\", %zu", original_dest, strlcpy(original_dest, src, size));
// 	printf(", %d", ft_strlen(original_dest));
// 	return 0;
// }