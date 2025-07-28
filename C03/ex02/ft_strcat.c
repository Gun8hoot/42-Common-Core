/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:07:30 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/21 13:29:14 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	cursor;
	int	len;

	cursor = 0;
	len = 0;
	while (dest[cursor] != '\0')
	{
		cursor++;
	}
	while (src[len] != '\0')
	{
		dest[cursor + len] = src[len];
		len++;
	}
	dest[cursor + len] = '\0';
	return (dest);
}
/* Verifier */

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	src[128] = "   Malhas   dlas";
// 	char	dest[128] = "Helloworld";
// 	char	odest[128] = "Helloworld";

// 	printf("src ; \"%s\", dest ; \"%s\"\n", src, dest);
// 	ft_strcat(dest, src);
// 	printf("Modif ; \"%s\"\n", dest);
// 	printf("strcat ; \"%s\"\n", strcat(odest, src));
// 	printf("strcmp ; %d\n", strcmp(dest, odest));
// 	return (0);
// }
