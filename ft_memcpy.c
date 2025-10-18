/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:40:51 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/18 14:24:35 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*tmp_dest;
	const unsigned char	*tpm_src;
	size_t	i;

	i = 0;
	tmp_dest = (unsigned char *)dest;
	tpm_src = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		tmp_dest[i] = tpm_src[i];
		i++;
	}
	return (tmp_dest);
}

// int main()
// {
//     char arr[] = "Hellozww";
//     const size_t goofy = ft_strlen(arr);
// 	char arrr2[goofy];
//     char *ret;
// 	ret = malloc(1000000);
//     int i = 0;
//     ret = ft_memcpy("s", "asdas", 14);
//     printf("%s\n", ret);
// 	free(ret);
//     return (0);
// }