/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:05:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/23 15:10:44 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}

// int main(void)
// {
// 	t_list	*aaa;
// 	t_list	*bbb;
// 	t_list	*ccc;
// 	t_list	*ddd;
// 	t_list	*tmp;

// 	aaa = ft_lstnew("1");
// 	bbb = ft_lstnew("2");
// 	ccc = ft_lstnew("3");
// 	ddd = ft_lstnew("4");
// 	tmp = ft_lstnew("goofy");

// 	aaa->next = bbb;
// 	bbb->next = ccc;
// 	ccc->next = ddd;
// 	ddd->next = NULL;

// 	ft_lstadd_front(&bbb, tmp);
// 	ft_lstadd_front(&tmp, aaa);

// 	for (int i = 0; aaa ;i++)
// 	{
// 		printf("%s\n", (char *)aaa->content);
// 		aaa = aaa->next;
// 	}
// }