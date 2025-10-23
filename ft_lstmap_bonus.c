/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:21:02 by nclavel           #+#    #+#             */
/*   Updated: 2025/10/23 13:21:51 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nodes;
	t_list	*cp_lst;

	nodes = lst;
	while (lst)
	{
		cp_lst = lst;
		f(cp_lst);
		if (!nodes)
		{
			del(cp_lst);
			return ;
		}
		nodes = nodes->next;
	}
}

int main(void)
{
	t_list	*aaa = ft_lstnew(ft_strdup("aaa"));
	t_list	*bbb = ft_lstnew(ft_strdup("bbb"));
	t_list	*ccc = ft_lstnew(ft_strdup("ccc"));
	t_list	*ddd = ft_lstnew(ft_strdup("ddd"));
	return (0);
}