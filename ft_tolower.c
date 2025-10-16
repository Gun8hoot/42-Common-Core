/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:43:57 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/14 09:46:19 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
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