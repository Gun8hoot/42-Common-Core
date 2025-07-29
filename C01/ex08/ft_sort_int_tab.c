/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:53:36 by nclavel           #+#    #+#             */
/*   Updated: 2025/07/29 09:27:16 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	already_swap;

	already_swap = 0;
	i = 0;
	j = 0;
	while (i < size - 1)
	{
		already_swap = 0;
		while (j < size - 1)
	}
}

int	main(void)
{
	int	tab = {9, 5 ,4 ,59, 26, 1, 37};
	int	size = 7;

	
}
