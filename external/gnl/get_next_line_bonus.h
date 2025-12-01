/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:11:52 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/14 07:42:53 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD 
#  define MAX_FD 1024
# endif

char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strdup(const char *s);
size_t	ft_gnl_strcpy(char *dst, const char *src);
size_t	ft_strlen(const char *s);

#endif