/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:15:40 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 13:18:01 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	f(void	*content)
{
	size_t	i;

	i = 0;
	while (((char *)content)[i])
	{
		if (((char *)content)[i] >= 'a' && ((char *)content)[i] <= 'z')
			((char *)content)[i] = ((char *)content)[i] - 32;
		i++;
	}
}
// int main(void)
// {
// 	t_list	*lst1;
// 	t_list	*lst2;
// 	t_list	*lst3;
// 	t_list	*lst4;
// 	lst1 = ft_lstnew(ft_strdup("lst1"));
// 	lst2 = ft_lstnew(ft_strdup("lst2"));
// 	lst3 = ft_lstnew(ft_strdup("lst3"));
// 	lst4 = ft_lstnew(ft_strdup("lst4"));
// 	lst1->next = lst2;
// 	lst2->next = lst3;
// 	lst3->next = lst4;
// 	lst4->next = NULL;
// 	ft_lstiter(lst1, &f);
// 	while (lst1)
// 	{
// 		printf("%s\n", (char *)lst1->content);
// 		lst1 = lst1->next;
// 	}
// 	return (0);
// }
