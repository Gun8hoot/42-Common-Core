/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 23:25:59 by memillet          #+#    #+#             */
/*   Updated: 2025/07/27 23:30:09 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "numbdict.h"
#include "basic.h"

char	*fortwoten(char *tab, t_dico *dict, int line)
{
	write(1, dict[line].valeur, ft_strlen(dict[line].valeur));
	write (1, " ", 1);
	tab = remove_first_char(tab);
	tab = remove_first_char(tab);
	return (tab);
}

char	for_two_twnty(char tab, t_dico *dict, int line)
{
	int	j;

	j = 0;
	write (1, dict[j].valeur, ft_strlen(dict[j].valeur));
	write (1, " ", 1);
	tab = remove_first_char(tab);
	return (tab);
}

char	*fortwo(char *tab, t_dico *dict)
{
	int	j;

	j = 10;
	if (tab[0] == '0')
	{
		tab = remove_first_char(tab);
		return (tab);
	}
	while (ft_strlen(tab) == 2 && j <= 19)
	{
		if (ft_strcmp(dict[j].cle, tab) == 0)
		{
			tab = fortwoten(tab, dict, j);
			return (tab);
		}
		j++;
	}
	while (ft_strlen(tab) == 2 && j <= 27)
	{
		if (dict[j].cle[0] - tab[0] == 0)
			tab = fortwotwo(tab, dict, j);
		j++;
	}
	return (NULL);
}

char	*forone(char *tab, t_dico *dict)
{
	int		j;
	char	*old;

	old = tab;
	j = 0;
	if (tab[0] == '0')
	{
		tab = remove_first_char(tab);
		free(old);
		return (tab);
	}
	while (ft_strlen(tab) == 1 && j <= 9)
	{
		if (ft_strcmp(dict[j].cle, tab) == 0)
		{
			write(1, dict[j].valeur, ft_strlen(dict[j].valeur));
			write (1, " ", 1);
			tab = remove_first_char(tab);
			free(old);
			return (tab);
		}
		j++;
	}
	return (NULL);
}

char	*forthree(char *tab, t_dico *dict)
{
	int		j;

	j = 0;
	if (tab[0] == '0')
	{
		tab = remove_first_char(tab);
		return (tab);
	}
	while (ft_strlen(tab) == 3 && j <= 9)
	{
		if (dict[j].cle[0] - tab[0] == 0)
		{
			write(1, dict[j].valeur, ft_strlen(dict[j].valeur));
			tab = remove_first_char(tab);
			write (1, " hundred ", 9);
			return (tab);
		}
		j++;
	}
	return (NULL);
}
