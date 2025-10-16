/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:00:28 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/16 17:47:28 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	void	*a;
	void	*b;

	a = (char *)src;
	b = (char *)dest;
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	i = 0;
	return (dest);
}

int main(int argc, char **argv)
{
	int i;
	char	*arr = "strtocpoy";
	char	*test = "strtocpoy";
	char	aaa[64];
	char	bbb[64];	
	i = 0;
	char *tt = ft_memmove(aaa, arr, 9);
	char *yy = memmove(bbb, test, 9);
	printf("%s\n%s", yy, tt);
}
