/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:12:40 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/17 17:25:14 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*elem;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		elem = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = elem;
	}
	*lst = NULL;
}

// void del(void *content)
// {
// 	free(content);
// // }
// int main(void)
// {
// 	t_stack	*aaa;
// 	t_stack	*bbb;
// 	t_stack	*ccc;
// 	t_stack	*ddd;

// 	aaa = ft_lstnew(ft_strdup("aaa"));
// 	bbb = ft_lstnew(ft_strdup("aaa"));
// 	ccc = ft_lstnew(ft_strdup("aaa"));
// 	ddd = ft_lstnew(ft_strdup("aaa"));

// 	aaa->next = bbb;
// 	bbb->next = ccc;
// 	ccc->next = ddd;
// 	ddd->next = NULL;

// 	ft_lstclear(&aaa, &del);
// }