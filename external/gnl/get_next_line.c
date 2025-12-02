/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:27:07 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/02 10:59:48 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_extract_next(char *static_vars)
{
	char	*first_next_letter;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (static_vars[i] && static_vars[i] != '\n')
		i++;
	first_next_letter = malloc(sizeof(char) * (ft_strlen(static_vars) - i + 1));
	if (!first_next_letter)
		return (NULL);
	if (static_vars[i] == '\n')
		i++;
	while (static_vars[i])
	{
		first_next_letter[j] = static_vars[i];
		i++;
		j++;
	}
	first_next_letter[j] = '\0';
	free(static_vars);
	return (first_next_letter);
}

char	*ft_safe_dup(char *static_vars)
{
	char	*line;

	if (!static_vars || !static_vars[0])
		return (NULL);
	line = ft_gnl_strdup(static_vars);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_readnstock(int fd, char *static_vars)
{
	char	*buffer;
	ssize_t	bytes;

	bytes = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_gnl_strchr(static_vars, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			if (static_vars)
				free(static_vars);
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		static_vars = ft_gnl_strjoin(static_vars, buffer);
	}
	free(buffer);
	return (static_vars);
}

char	*get_next_line(int fd)
{
	static char	*static_vars;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(static_vars);
		static_vars = NULL;
		return (NULL);
	}
	static_vars = ft_readnstock(fd, static_vars);
	if (!static_vars || !static_vars[0])
	{
		if (static_vars)
			free(static_vars);
		static_vars = NULL;
		return (NULL);
	}
	line = ft_safe_dup(static_vars);
	static_vars = ft_extract_next(static_vars);
	return (line);
}

// #include <stdio.h>
// int main(void)
// {
// 	// ANTI MAIN PUSH
// 	int		fd = open("text", O_RDONLY);
// 	char	*line;

// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 	}
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	close(fd);
// 	return (EXIT_SUCCESS);
// }