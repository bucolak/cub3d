/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:14:10 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/27 19:08:22 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	identifier_check(t_header *header, char *line)
{
	char	*ptr;

	ptr = line;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	if (!ft_strncmp(ptr, "NO", 2) && ft_isspace(ptr[2]))
		header->type = NO;
	else if (!ft_strncmp(ptr, "SO", 2) && ft_isspace(ptr[2]))
		header->type = SO;
	else if (!ft_strncmp(ptr, "WE", 2) && ft_isspace(ptr[2]))
		header->type = WE;
	else if (!ft_strncmp(ptr, "EA", 2) && ft_isspace(ptr[2]))
		header->type = EA;
	else if (!ft_strncmp(ptr, "F", 1) && ft_isspace(ptr[1]))
		header->type = F;
	else if (!ft_strncmp(ptr, "C", 1) && ft_isspace(ptr[1]))
		header->type = C;
	else
	{
		header->type = ERROR;
	}
}

static int	f_c_load(t_header *header, char *ptr)
{
	int		i;
	char	**temp;
	char	*trim;

	i = 0;
	temp = ft_split(ptr, ',');
	if (!temp || !temp[0] || !temp[1] || !temp[2] || temp[3])
	{
		free_2d_array(temp);
		return 0;
	}
	while (i < 3)
	{
		trim = ft_strtrim(temp[i], " \t\n");
		if (!trim || !*trim)
		{
			free_2d_array(temp);
			free(trim);
			return 0;
		}
		if (header->type == F)
			header->f_rgb[i] = ft_atol(trim);
		else
			header->c_rgb[i] = ft_atol(trim);
		free(trim);
		if (((header->type == F) && (header->f_rgb[i] == -1))
			|| ((header->type == C) && (header->c_rgb[i] == -1)))
			{
				free_2d_array(temp);
				return 0;
			}
		i++;
	}
	free_2d_array(temp);
	return 1;
}

static int	identifier_load(t_header *header, t_map *map, char *line, int fd)
{
	char *rgb;
	
	if (header->type == NO)
	{
		if (header->no_path) // bu kontrollerin sebebi map5te 2 tane north var örneğin, oz aman leak oluyodu o yüzden bi kere atama yapıyoruz
			return -1;
		header->no_path = ft_path_maker(line, header, map,fd);
	}
	else if (header->type == SO)
	{
		if (header->so_path)
			return -1;
		header->so_path = ft_path_maker(line, header, map,fd);
	}
	else if (header->type == WE)
	{
		if (header->we_path)
			return -1;
		header->we_path = ft_path_maker(line, header, map,fd);
	}
	else if (header->type == EA)
	{
		if (header->ea_path)
			return -1;
		header->ea_path = ft_path_maker(line, header, map,fd);
	}
	else if (header->type == F || header->type == C)
	{
		rgb = ft_path_maker(line, header, map,fd);
		if(!f_c_load(header, rgb))
		{
			free(rgb);
			return 0;
		}
		free(rgb);
	}
	if(is_xpm_valid(header, header->type) == 0)
		return 2;
	return 1;
}

static int	is_map_started(char *line)
{
	int	i;
	int verify_map;

	verify_map = 1;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W' || line[i] == ' '))
			verify_map = 0;;
		i++;
	}
	return (verify_map);
}

void	header_parse(int fd, t_header *header, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if(!line)
		error_exit_all("Empty Map!", header, map, NULL);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		if (header->ea_path && header->we_path && header->so_path 
			&& header->no_path && is_map_started(line) == 1)
		{
			if (header->flag == 6)
			{
				raw_map_filler(line, map, fd, header);
				break ;
			}
			else
			{
				free(line);
				cleanup_gnl(fd);
				error_exit_all("Please enter identifiers correctly!", header,
					map, NULL);
			}
		}
		else
		{
			identifier_check(header, line);
			if (header->type == ERROR)
			{
				free(line);
				cleanup_gnl(fd);
				error_exit_all("Please enter identifiers correctly!", header,
					map, NULL);
			}
			if(identifier_load(header, map, line, fd) == 0)
			{
				free(line);
				cleanup_gnl(fd);
				error_exit_all("Invalid RGB!", header, map, NULL);
			}
			else if(identifier_load(header, map, line, fd) == -1)
			{
				free(line);
				cleanup_gnl(fd);
				error_exit_all("Please enter identifiers correctly!", header,
					map, NULL);
			}
			else if(identifier_load(header, map, line, fd) == 2)
			{
				free(line);
				cleanup_gnl(fd);
				error_exit_all("Wrong XPM Format!", header, map, NULL);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
}
