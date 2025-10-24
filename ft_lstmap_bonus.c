/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:21:02 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/24 16:58:36 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cp_lst;
	t_list	*nodes;

	while (lst != NULL)
	{
		nodes = ft_lstnew(f(lst->content));
		if (!nodes)
		{
			del(nodes);
			ft_lstclear(&nodes, del);
			return (NULL);
		}
		cp_lst = nodes;
		lst = lst->next;
	}
	cp_lst->next = NULL;
	return (cp_lst);
}

// void *f(void *c)
// {
// 	int i;

// 	i = 0;
// 	while (((char *)c)[i])
// 	{
// 		if (((char *)c)[i] >= 'a' && ((char *)c)[i] <= 'z')
// 			((char *)c)[i] -= 32;
// 		i++;
// 	}
// 	return (c);
// }

// void del(void *s)
// {
// 	(void)s;
// }
// int main(void)
// {
// 	int i = 1;
// 	t_list	*aaa = ft_lstnew(ft_strdup("Content On the N0de n1"));
// 	t_list	*bbb = ft_lstnew(ft_strdup("anotHER conTent"));
// 	t_list	*ccc = ft_lstnew(ft_strdup("also content here"));
// 	t_list	*ddd = ft_lstnew(ft_strdup("LasT CONTENT, PromISE"));
// 	t_list	*lst = NULL;

// 	ft_lstadd_back(&lst, aaa);
// 	ft_lstadd_back(&lst, bbb);
// 	ft_lstadd_back(&lst, ccc);
// 	ft_lstadd_back(&lst, ddd);
// 	t_list	*cp	 = ft_lstmap(lst, f, del);
// 	while (lst)
// 	{
// 		printf("node n'%d :\t\"%s\"\n", i, (char *)lst->content);
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (0);
// }