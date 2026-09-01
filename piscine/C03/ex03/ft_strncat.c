/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:27:07 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/22 14:41:51 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				cursor;
	unsigned int	len;

	cursor = 0;
	len = 0;
	while (dest[cursor] != '\0')
	{
		cursor++;
	}
	while (src[len] != '\0' && len < nb)
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
// 	char	src[128] = " $sasdMaisnancamarche";
// 	char	dest[128] = "HEllowolrd";
// 	char	odest[128] = "HEllowolrd";
// 	int	nb = 10;

// 	printf("src ; \"%s\", dest ; \"%s\"\n", src, dest);
// 	ft_strncat(dest, src, nb);
// 	printf("Modif ; %s\n", dest);
// 	printf("strncat ; %s\n", strncat(odest, src, nb));
// 	printf("strcmp ; %d\n", strcmp(dest, odest));
// 	return (0);
// }
