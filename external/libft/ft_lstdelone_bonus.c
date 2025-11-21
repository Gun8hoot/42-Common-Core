/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:49:48 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/17 17:25:14 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_stack *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void del(void *elem)
// {
// 	printf("asd\n");
// 	elem = NULL;
// }
// int main(void)
// {
// 	t_stack	*aaa;
// 	t_stack	*bbb;
// 	t_stack	*ccc;
// 	t_stack	*ddd;
// 	aaa = ft_lstnew("aaa");
// 	bbb = ft_lstnew("bbb");
// 	ccc = ft_lstnew("ccc");
// 	ddd = ft_lstnew("ddd");
// 	aaa->next = bbb;
// 	bbb->next = ccc;
// 	ccc->next = ddd;
// 	ddd->next = NULL;
// 	ft_lstdelone(ccc, &del);
// 	printf("%s\n", (char *)ccc);
// 	for (int i = 0;aaa;i++)
// 	{
// 		printf("%s\n", (char *)aaa);
// 		aaa = aaa->next;
// 	}
// }