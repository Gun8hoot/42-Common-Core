/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:27:07 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/14 07:52:06 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	static char	*static_vars[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(static_vars[fd]);
		return (NULL);
	}
	static_vars[fd] = ft_readnstock(fd, static_vars[fd]);
	if (!static_vars[fd] || !static_vars[fd][0])
	{
		if (static_vars[fd])
			free(static_vars[fd]);
		return (static_vars[fd] = NULL, NULL);
	}
	line = ft_safe_dup(static_vars[fd]);
	static_vars[fd] = ft_extract_next(static_vars[fd]);
	return (line);
}

// #include <stdio.h>
// int main(void)
// {
// 	// ANTI MAIN PUSH
// 	int		fd1 = open("file1", O_RDONLY);
// 	int		fd2 = open("file2", O_RDONLY);
// 	int		fd3 = open("file3", O_RDONLY);
// 	char	*line;

// 	printf("FD1 - File : \n");
// 	while ((line = get_next_line(fd1)))
// 		printf("%s", line);
// 	printf("FD2 - File : \n");
// 	while ((line = get_next_line(fd2)))
// 		printf("%s", line);
// 	printf("FD3 - File : \n");
// 	while ((line = get_next_line(fd3)))
// 		printf("%s", line);
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
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (EXIT_SUCCESS);
// }