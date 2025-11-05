/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:30:42 by buket             #+#    #+#             */
/*   Updated: 2025/11/05 11:10:10 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*f_read(int fd, char *buffer)
{
	char	*line;
	int		read_byte;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	read_byte = 1;
	while (!new_check(buffer, '\0') && read_byte > 0)
	{
		read_byte = read(fd, line, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		line[read_byte] = '\0';
		buffer = gnl_strjoin(buffer, line);
	}
	free(line);
	return (buffer);
}

char	*f_swap(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	while (buffer[j] && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
	{
		line[j] = buffer[i];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_new(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		i++;
	}
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)malloc(gnl_strlen(buffer) - i + 1);
	if (!line)
		return (NULL);
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = f_read(fd, buffer);
	if (!buffer || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = f_swap(buffer);
	buffer = get_new(buffer);
	return (line);
}
