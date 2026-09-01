/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 05:14:06 by lbardet-          #+#    #+#             */
/*   Updated: 2025/07/27 17:39:25 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_H
# define BASIC_H

int		ft_strlen(char *str);
void	ft_putstr(char *str);
char	*ft_strndup(char *src, int n);
char	*ft_strcpy(char *dest, char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *src);
char	**ft_malloc(char **tab, int len);
char	**ft_split(char *str, char *sep);
char	**remplir_tab(char **tab, char *liste);
char	**alloc_tab(char *liste_nb);
char	*recup_lst(void);
char	**ft_strcat(char **dest, char **src);

#endif