/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 23:23:09 by memillet          #+#    #+#             */
/*   Updated: 2025/07/27 23:30:04 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "numbdict.h"
#include "basic.h"

char	**skip_zero(char **tab2, int pose)
{
	while (tab2[pose] != NULL && tab2[pose][0] == '0')
	{
		tab2[pose] = remove_first_char(tab2[pose]);
		if (tab2[pose][0] == '\0')
			pose++;
	}
	return (tab2);
}

char	**printnumb(t_dico *dict, char **tab2, int pose)
{
	int	i;
	int	j;
	int	temp;

	temp = pose;
	j = 27;
	i = 0;
	while (tab2[pose])
	{
		pose++;
		i++;
	}
	write(1, dict[j + i].valeur, ft_strlen(dict[j + i].valeur));
	write (1, " ", 1);
	if (tab2[pose + 1] != NULL && tab2[pose + 1][0] == '0')
	{
		tab2 = skip_zero(tab2, temp);
		return (tab2);
	}
	return (tab2);
}

void	print_value(char **tab2, t_dico *dict)
{
	int		i;

	i = 0;
	while (tab2[i] != NULL)
	{
		while (tab2[i][0] != '\0')
		{
			if (ft_strlen(tab2[i]) == 3)
				tab2[i] = forthree(tab2[i], dict);
			if (ft_strlen(tab2[i]) == 2)
				tab2[i] = fortwo(tab2[i], dict);
			if (ft_strlen(tab2[i]) == 1)
				tab2[i] = forone(tab2[i], dict);
		}
		if (tab2[i + 1] != NULL)
			printnumb(dict, tab2, i);
		i++;
	}
	write(1, "\n", 1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_dict(t_dico *dict)
{
	int	i;

	i = 0;
	while (dict[i].cle && dict[i].valeur)
	{
		free(dict[i].cle);
		free(dict[i].valeur);
		i++;
	}
	free(dict);
}
