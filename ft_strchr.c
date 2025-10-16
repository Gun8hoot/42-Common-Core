/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:50:58 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/15 09:13:53 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     // define a string
//     const char* str = "GeeksforGeeks";
//     // define a char ch to be searched in str
//     char ch = 's';

//     // Use strchr to find the first occurrence of the
//     // character 's'
//     const char* result = ft_strchr(str, ch);
//     const char* tmp = strchr(str, ch);

//     if (result != NULL) {
//         // Calculate the position by subtracting the base
//         // pointer from the result pointer
//         printf("Character '%c' found at position: %ld %s\n",
//                ch, result - str, result);
//     }
//     else {
//         printf("Character '%c' not found.\n", ch);
//     }

//     return 0;
// }