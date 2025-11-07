/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:14:10 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/08 00:23:45 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void has_extra_char(t_map *map, t_header *header, char *line)
{
	if (ft_strchr(line, '1'))
	{
		free(line);
		error_exit_all("Extra char in map!", header, map);
	}
	free(line);
}

static int on_the_map(t_map *map, t_header *header, char *line, int fd)
{
	int j;

	j = 0;
	if(is_map_started(line) == 1)
	{
		map->raw_map[j++] = ft_strdup(line);
		free(line);
		while((line = get_next_line(fd)) != NULL)
		{
			if(ft_strcmp(line, "\n") != 0)
				map->raw_map[j++] = ft_strdup(line);
			else
			{
				free(line);
				while ((line = get_next_line(fd)) != NULL)
					has_extra_char(map, header, line);
				break;
			}
			if(line)
				free(line);
		}
		return j;
	}
	return -1;
}

static int	handle_line_type(char *line, t_header *header, t_map *map, int fd)
{
	int	type;
	int map_index;
	
	type = identifier_check(header, line);
	identifier_load(header, map, line, type);
	map_index = on_the_map(map, header, line, fd);
    if (map_index != -1)
	{
		return (map_index);
	}
	free(line);
	return (0);
}

static void read_loop(t_map *map, t_header *header, int fd)
{
	char *line;
	int i;
	int map_end_index;

	while((line = get_next_line(fd)) != NULL)
	{
		if(ft_strcmp(line, "\n") == 0)
		{
			free(line);			
			continue;
		}
		i = 0;
		while(line[i] && line[i] == ' ')
			i++;
		map_end_index = handle_line_type(line, header, map, fd);
        if (map_end_index > 0)
            break;
	}
	map->raw_map[map_end_index] = NULL;
}

static void count_line_and_malloc(t_map *map, t_header *header, char *header_map)
{
	int i;
	int fd;
	char *line;
	
	i = 0;
	fd = open(header_map, O_RDONLY);
	line = get_next_line(fd);
	if(!line)
		error_exit_all("Empty Map!", header, map);
	i = 0;
	while(line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->raw_map = malloc(sizeof(char *) * (i + 1));
}

void read_entire_file(char *header_map, t_map *map, t_header *header)
{
	int fd;

	count_line_and_malloc(map, header, header_map);
	fd = open(header_map, O_RDONLY);
	read_loop(map, header, fd);
	close(fd);
}
