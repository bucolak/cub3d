/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:14:10 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/05 18:36:37 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	count_map_lines(char *header_map, t_header *init, t_map *init_map)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(header_map, O_RDONLY);
	if (fd < 0)
		error_exit_all("Invalid fd", init, init_map);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

static int	is_map_started(char *line, char *header_map, t_header *init,
		t_map *init_map)
{
	int	i;
	int	line_count;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			line_count = count_map_lines(header_map, init, init_map);
			init_map->raw_map = malloc(sizeof(char *) * (line_count + 1));
			if (!init_map->raw_map)
				error_exit_all("Error: Memory allocation failed", init,
					init_map);
			init_map->raw_map[line_count] = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}

void	process_header_line(char *line, t_header *init, t_map *init_map)
{
	identifier_check(init, line);
	if (init->type == ERROR)
	{
		free(line);
		error_exit_all("Please enter identifiers correctly!!\n", init,
			init_map);
	}
	identifier_load(init, init_map, line);
}

void	process_map_line(int fd, t_map *init_map, int *i)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		init_map->raw_map[*i] = ft_strdup(line);
		(*i)++;
		free(line);
	}
}

void	header_parse(char *header_map, t_header *init, t_map *init_map)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(header_map, O_RDONLY);
	if (fd < 0)
		error_exit_all("Invalid fd", init, init_map);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_started(line, header_map, init, init_map) == 1)
		{
			init_map->raw_map[i] = ft_strdup(line);
			process_map_line(fd, init_map, &i);
			break ;
		}
		else
			process_header_line(line, init, init_map);
		free(line);
	}
	close(fd);
}
