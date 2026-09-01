/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:06:01 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/20 16:20:32 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	unsigned int n = 3;
// 	char	src[] = "a";
// 	char	dest[] = "destination";
// 	char	odest[] = "destination";

// 	ft_strncpy(dest, src, n);
// 	printf("\nft_strncpy = %s\n", dest);
// 	printf("strncpy = %s\n", strncpy(odest, src, n));
// 	printf("strcmp ; %d\n", strcmp(dest, odest));
// 	return (0);
// }