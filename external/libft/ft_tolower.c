/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:43:57 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/17 15:57:36 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// #include <stdio.h>
// int main(void)
// {
// 	char arr[] = "ASDSADS";
// 	char aaa[255];
// 	int	i;
// 	i  = 0;
// 	while (i < 18)
// 	{
// 		aaa[i] = ft_tolower(arr[i]);
// 		i++;
// 	}
// 	printf("%s", aaa);
// 	return (0);
// }