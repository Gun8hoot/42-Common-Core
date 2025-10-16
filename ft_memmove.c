/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:00:28 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/15 12:19:29 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	tmp[1024];

	i = 0;
	while (i < n)
	{
		tmp[i] = ((char *)src)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = tmp[i];
		i++;
	}
	return (dest);
}

int main(void)
{
	int i;
	char	arr[] = "Goofy strasdasdsadsadsadsadsadsadsadsadasdasdasdsadsadstrasdasdsadsadsadsadsadsadsadsadasdasdasdsadsadstrasdasdsadsadsadsadsadsadsadsadasdasdasdsadsad";
	char	test[] = "Goofy strasdasdsadsadsadsadsadsadsadsadasdasdasdsadsadstrasdasdsadsadsadsadsadsadsadsadasdasdasdsadsadstrasdasdsadsadsadsadsadsadsadsadasdasdasdsadsad";
	char	aaa[64];
	char	bbb[64];	
	i = 0;
	char *tt = ft_memmove(aaa, arr, 9 + 1);
	char *yy = memmove(bbb, test, 9 + 1);
	printf("%s\n%s\n", tt, yy);
}
