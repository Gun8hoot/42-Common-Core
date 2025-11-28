/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:00:13 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/28 08:33:35 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

long long	ft_atol(char *number)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((number[i] >= 9 && number[i] <= 13) || number[i] == ' ')
		i++;
	if (number[i] == '-' || number[i] == '+')
	{
		if (number[i] == '-')
			sign = -sign;
		i++;
	}
	while (number[i] >= '0' && number[i] <= '9')
	{
		res = res * 10 + (number[i] - '0');
		i++;
	}
	return (res * sign);
}

int	check_int_overflow(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) > 11 || ft_atol(tab[i]) > INT_MAX
			|| ft_atol(tab[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_number_only(char **tab)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (tab[i])
	{
		j = 0;
		sign = 0;
		while (tab[i][j])
		{
			if ((!ft_isdigit((tab[i][j])) && sign == 1)
				|| (!ft_isdigit((tab[i][j])) && (tab[i][j] != '-' 
						&& tab[i][j] != '+')))
				return (0);
			if (tab[i][j] == '-' || tab[i][j] == '+')
				sign = 1;
			if ((tab[i][j] == '-' && !tab[i][j + 1]) || (tab[i][j] == '+'
					&& !tab[i][j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicate(char **tab, int len)
{
	int	i;
	int	j;
	int	skip_once;

	i = 0;
	while (tab[i])
	{
		skip_once = 0;
		j = 0;
		while (j < len)
		{
			if ((ft_atoi(tab[i]) == ft_atoi(tab[j])) && skip_once == 1)
				return (0);
			else if ((ft_atoi(tab[i]) == ft_atoi(tab[j])) && skip_once == 0)
				skip_once = 1;
			j++;
		}
		i++;
	}
	return (1);
}

int	*check_all_n_convert(char **tab)
{
	int	*converted;
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (tab[len])
		len++;
	if (!check_number_only(tab) || !check_int_overflow(tab)
		|| !check_duplicate(tab, len))
		return (NULL);
	converted = ft_calloc(len, sizeof(int));
	if (!converted)
		return (NULL);
	while (tab[i])
	{
		converted[i] = ft_atoi(tab[i]);
		i++;
	}
	return (converted);
}
