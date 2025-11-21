/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:45:43 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/17 17:25:14 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*back;

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
// 	t_stack	*aaa;
// 	t_stack	*bbb;
// 	t_stack	*ccc;
// 	t_stack	*ddd;
// 	t_stack	*tmp;
// 	t_stack	*empty;

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