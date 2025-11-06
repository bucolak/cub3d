/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 01:33:28 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/06 18:01:45 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	control_valid_map(t_map *map, t_header *header, int i, int j)
{
	if (j > 0 && map->raw_map[i][j - 1] && map->raw_map[i][j - 1] != '1'
		&& map->raw_map[i][j - 1] != ' ')
		error_exit_all("Invalid map!", header, map);
	if (map->raw_map[i][j + 1] && map->raw_map[i][j + 1] != '1'
		&& map->raw_map[i][j + 1] != ' ')
		error_exit_all("Invalid map!", header, map);
	if (i > 0 && j < (int)ft_strlen(map->raw_map[i - 1]) && map->raw_map[i - 1][j]
		&& map->raw_map[i - 1][j] != '1' && map->raw_map[i - 1][j] != ' ')
		error_exit_all("Invalid map!", header, map);
	if (map->raw_map[i + 1] && j < (int)ft_strlen(map->raw_map[i + 1])
		&& map->raw_map[i + 1][j] != '1' && map->raw_map[i + 1][j] != ' ')
		error_exit_all("Invalid map!", header, map);
}

void	is_valid_map(t_map *map, t_header *header)
{
	int	i;
	int	j;

	if (map->player_x < 0 || map->player_x >= map->width || map->player_y < 0
		|| map->player_y >= map->height)
		return ;
	i = -1;
	while (map->raw_map[++i])
	{
		j = -1;
		while (map->raw_map[i][++j])
		{
			if (map->raw_map[i][j] == ' ')
				control_valid_map(map, header, i, j);
		}
	}
}
