/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:45:43 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/22 13:07:17 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	back = ft_lstlast(*lst);
	back->next = new;
}

// int main(void)
// {
// 	t_list	*aaa;
// 	t_list	*bbb;
// 	t_list	*ccc;
// 	t_list	*ddd;
// 	t_list	*tmp;
// 	t_list	*empty;

// 	aaa = ft_lstnew("aaa");
// 	bbb = ft_lstnew("bbb");
// 	ccc = ft_lstnew("ccc");
// 	ddd = ft_lstnew("ddd");
// 	tmp = ft_lstnew("END");

// 	aaa->next = bbb;
// 	bbb->next = ccc;
// 	ccc->next = ddd;
// 	ddd->next = NULL;

// 	ft_lstadd_back(&aaa, tmp);

// 	for (int i = 0;aaa;i++)
// 	{
// 		printf("%s\n", (char *)aaa->content);
// 		aaa = aaa->next;
// 	}
// }