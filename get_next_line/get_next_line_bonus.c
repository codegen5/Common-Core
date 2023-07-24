/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:35:43 by msamilog          #+#    #+#             */
/*   Updated: 2023/07/24 04:51:07 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static inline
char	*ft_buffer(int fd, char *buffer, char *remainder)
{
	ssize_t	bytes_read;
	size_t	i;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (!bytes_read)
			break ;
		buffer[bytes_read] = '\0';
		if (!remainder)
		{
			remainder = (char *)malloc(sizeof(char));
			*remainder = '\0';
		}
		remainder = ft_strjoin(remainder, buffer);
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
			break ;
	}
	return (remainder);
}

static inline
char	*trim_line(char *line)
{
	size_t	i;
	char	*remainder;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0')
		return (NULL);
	remainder = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[i + 1] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*remainder[10240];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (remainder[fd])
			free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_buffer(fd, buffer, remainder[fd]);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remainder[fd] = trim_line(line);
	return (line);
}
