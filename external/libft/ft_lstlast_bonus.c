/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:42:22 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/17 17:25:14 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main(void)
// {
// 	t_stack *aaa;
// 	t_stack *bbb;
// 	t_stack *ccc;
// 	t_stack *ddd;
// 	t_stack *eee;

// 	aaa = ft_lstnew("aaa");
// 	bbb = ft_lstnew("bbb");
// 	ccc = ft_lstnew("ccc");
// 	ddd = ft_lstnew("ddd");
// 	eee = ft_lstnew("eee");

// 	aaa->next = bbb;
// 	bbb->next = ccc;
// 	ccc->next = ddd;
// 	ddd->next = eee;
// 	eee->next = NULL;

// 	printf("%s\n", (char *)ft_lstlast(aaa)->content);
// }