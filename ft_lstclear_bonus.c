/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:12:40 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/23 15:43:32 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		elem = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = elem;
	}
	*lst = NULL;
}

// void del(void *content)
// {
// 	free(content);
// }

// int main(void)
// {
// 	t_list	*aaa;
// 	t_list	*bbb;
// 	t_list	*ccc;
// 	t_list	*ddd;

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