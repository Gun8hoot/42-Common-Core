/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:36:12 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/18 12:58:13 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

//int main(void)
//{
//	char arr[] = "nedd Up upperCase";
//	char aaa[255];
//	int	i;
//
//	i  = 0;
//	while (i < 18)
//	{
//		aaa[i] = ft_toupper(arr[i]);
//		i++;
//	}
//	printf("%s", aaa);
//	return (0);
//}