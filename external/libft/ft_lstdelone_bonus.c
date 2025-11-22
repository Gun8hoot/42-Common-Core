/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:49:48 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/28 08:35:54 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
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
// 	t_list	*aaa;
// 	t_list	*bbb;
// 	t_list	*ccc;
// 	t_list	*ddd;
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