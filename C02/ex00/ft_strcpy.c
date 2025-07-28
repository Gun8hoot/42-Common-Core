/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:54:28 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/20 16:20:29 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	*src;
// 	char	dest[128];

// 	src = "Hello, World!";
// 	ft_strcpy(dest, src);
// 	printf("%s", dest);
// 	return (0);
// }