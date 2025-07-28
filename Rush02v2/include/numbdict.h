/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbdict.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 05:27:14 by lbardet-          #+#    #+#             */
/*   Updated: 2025/07/27 22:51:43 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBDICT_H
# define NUMBDICT_H
# define BUFFER 10000
# define MAXENTER 10000

typedef struct s_dico
{
	char	*cle;
	char	*valeur;
}	t_dico;

#endif