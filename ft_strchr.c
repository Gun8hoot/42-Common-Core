/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:50:58 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 09:25:58 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     const char* str = "GeeksforGeeks";
//     char ch = 's';

//     const char* result = ft_strchr(str, ch);

//     if (result != NULL) {
//         printf("Character '%c' found at position: %ld ; %s\n",
//                ch, result - str, result);
//     }
//     else {
//         printf("Character '%c' not found.\n", ch);
//     }
//     return 0;
// }