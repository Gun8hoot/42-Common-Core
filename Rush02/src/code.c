/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:39:34 by memillet          #+#    #+#             */
/*   Updated: 2025/07/27 23:27:10 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "numbdict.h"
#include "basic.h"

t_dico	parse_line(char *reaad, int size, int *p)
{
	t_dico	entry;
	int		start;

	while (*p < size && (reaad[*p] == '\n' || reaad[*p] == ' '))
		(*p)++;
	start = *p;
	while (*p < size && reaad[*p] != ':' && reaad[*p] != '\n')
		(*p)++;
	entry.cle = ft_strndup(reaad + start, *p - start);
	if (*p < size && reaad[*p] == ':')
		(*p)++;
	while (*p < size && (reaad[*p] == ' ' || reaad[*p] == '\n'))
		(*p)++;
	start = *p;
	while (*p < size && reaad[*p] != '\n')
		(*p)++;
	entry.valeur = ft_strndup(reaad + start, *p - start);
	if (*p < size && reaad[*p] == '\n')
		(*p)++;
	return (entry);
}

t_dico	*splitdict(int size, char *reaad)
{
	t_dico	*tab;
	int		i;
	int		p;

	tab = malloc(sizeof(t_dico) * BUFFER);
	if (!tab)
		return (NULL);
	i = 0;
	p = 0;
	while (p < size && i < MAXENTER)
	{
		tab[i] = parse_line(reaad, size, &p);
		i++;
	}
	tab[i].cle = NULL;
	tab[i].valeur = NULL;
	return (tab);
}

char	*remove_first_char(char *str)
{
	int		i;
	int		jcrochet;
	int		len;
	char	*new_str;

	i = 1;
	jcrochet = 0;
	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[jcrochet] = str[i];
		i++;
		jcrochet++;
	}
	new_str[jcrochet] = '\0';
	return (new_str);
}

char	*fill_0(char *str)
{
	int		i;
	int		diff;
	int		j;
	char	*str2;

	if (ft_strlen(str) % 3 == 0)
		return (str);
	diff = 3 - ft_strlen(str) % 3;
	i = 0;
	j = 0;
	str2 = malloc((sizeof(char) * ((ft_strlen(str) % 3) + diff + 30)));
	while (diff != 0)
	{
		str2[i] = '0';
		diff--;
		i++;
	}
	while (str[j])
	{
		str2[i] = str[j++];
		i++;
	}
	return (str2);
}

char	**tab_3(char *str)
{
	int		i;
	int		j;
	char	**tab;
	int		s;

	i = 0;
	j = 0;
	s = 0;
	str = fill_0(str);
	tab = malloc(sizeof(char *) * (ft_strlen(str) / 3 + 2));
	while (str[s])
	{
		tab[j] = malloc(sizeof(char) * 4);
		while (i != 3)
		{
			tab[j][i] = str[s];
			i++;
			s++;
		}
		tab[j][i] = '\0';
		j++;
		i = 0;
	}
	tab[j] = NULL;
	return (tab);
}
