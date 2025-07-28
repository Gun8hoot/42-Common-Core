/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:15:55 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/22 14:43:08 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	cursor;

	cursor = 0;
	while (s1[cursor] != '\0' || s2[cursor] != '\0')
	{
		if (s1[cursor] != s2[cursor])
		{
			return (s1[cursor] - s2[cursor]);
		}
		cursor++;
	}
	return (0);
}
/* Verifier */

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "1";
// 	s2 = "shffousdk[oabgy8whapjdsuila]";

// 	printf("Ma fonction ; %d\n", ft_strcmp(s1, s2));
// 	printf("Vrai strcmp ; %d\n", strcmp(s1, s2));
// }
