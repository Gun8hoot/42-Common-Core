/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:27:59 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/22 14:43:05 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	cursor;

	cursor = 0;
	while ((s1[cursor] || s2[cursor]) && cursor < n)
	{
		if (s1[cursor] != s2[cursor])
		{
			return (s1[cursor] - s2[cursor]);
		}
		cursor++;
	}
	return (0);
}
/* VERIFIER */
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	int	n;

// 	s1 = "abcdefg";
// 	s2 = "abcdefghijklmn";
// 	n = 6;	
// 	printf("\nMa fonction ; %d\n", ft_strncmp(s1, s2, n));
// 	printf("Vrai strncmp ; %d\n", strncmp(s1, s2, n));
// 	n++;
// }