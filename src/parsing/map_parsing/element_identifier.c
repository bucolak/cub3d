/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:22:49 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/06 18:04:01 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

char	*ft_path_maker(char *line, t_header *init, t_map *map)
{
	char	*ptr;
	char	*start;
	char	*end;
	char	*path;

	ptr = line;
	while (ft_isspace(*ptr))
		ptr++;
	ptr += 2;
	while (ft_isspace(*ptr))
		ptr++;
	if (init->type == F || init->type == C)
		return (ptr);
	start = ptr;
	end = start;
	while (*end && !ft_isspace(*end) && *end != '\n')
		end++;
	while (ft_isspace(*end))
		end++;
	if (*end != '\0')
		error_exit_all("Extra tokens in path line!!", init, map);
	path = ft_substr(start, 0, end - start);
	return (path);
}

void	identifier_check(t_header *init, char *line)
{
	char	*ptr;

	ptr = line;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	if (!ft_strncmp(ptr, "NO", 2) && ft_isspace(ptr[2]))
		init->type = NO;
	else if (!ft_strncmp(ptr, "SO", 2) && ft_isspace(ptr[2]))
		init->type = SO;
	else if (!ft_strncmp(ptr, "WE", 2) && ft_isspace(ptr[2]))
		init->type = WE;
	else if (!ft_strncmp(ptr, "EA", 2) && ft_isspace(ptr[2]))
		init->type = EA;
	else if (!ft_strncmp(ptr, "F", 1) && ft_isspace(ptr[1]))
		init->type = F;
	else if (!ft_strncmp(ptr, "C", 1) && ft_isspace(ptr[1]))
		init->type = C;
	else
		init->type = ERROR;
}

void	identifier_load(t_header *init, t_map *map, char *line)
{
	if (init->type == NO)
		init->no_path = ft_path_maker(line, init, map);
	else if (init->type == SO)
		init->so_path = ft_path_maker(line, init, map);
	else if (init->type == WE)
		init->we_path = ft_path_maker(line, init, map);
	else if (init->type == EA)
		init->ea_path = ft_path_maker(line, init, map);
	else if (init->type == F || init->type == C)
		f_c_load(init, map, ft_path_maker(line, init, map));
}

void	info(t_map *map)
{
	int	i;
	int	j;
	int	max;

	i = -1;
	while (map->raw_map[++i])
	{
		map->height++;
		j = 0;
		while (map->raw_map[i][j] && map->raw_map[i][j] != '\n')
			j++;
		max = j;
		if (max > map->width)
			map->width = max;
		j = -1;
		while (map->raw_map[i][++j])
		{
			if (map->raw_map[i][j] == 'N')
				map->orientation = N;
			if (map->raw_map[i][j] == 'S')
				map->orientation = S;
			if (map->raw_map[i][j] == 'W')
				map->orientation = W;
			if (map->raw_map[i][j] == 'E')
				map->orientation = E;
		}
	}
}

void	find_starting_coordinates(t_map *map) // playerın başlangıç kordinatı için
{
	int	i;
	int	j;

	i = -1;
	while (map->raw_map[++i])
	{
		j = -1;
		while (map->raw_map[i][++j])
		{
			if (map->raw_map[i][j] == 'N' || map->raw_map[i][j] == 'S'
				|| map->raw_map[i][j] == 'W' || map->raw_map[i][j] == 'E')
			{
				map->player_x = j; // Satır numarası (yukarıdan aşağıya)  Y
				map->player_y = i; // Sütun numarası (soldan sağa)	X
			}
		}
	}
}
