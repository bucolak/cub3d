/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:49:24 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/08 12:30:32 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	is_columns_closed(t_map *map, int i)
{
	int	j;

	while (i < map->height)
	{
		if (map->raw_map[i][0] != '1' && map->raw_map[i][0] != ' '
			&& map->raw_map[i][0] != '\n')
		{
			return (1);
		}
		j = 0;
		while (map->raw_map[i][j] && map->raw_map[i][j] != '\n')
			j++;
		if (j > 0 && map->raw_map[i][j - 1] != '1' && map->raw_map[i][j
			- 1] != ' ')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	is_raws_closed(t_map *map, int i)
{
	while (map->raw_map[0][i])
	{
		if (map->raw_map[0][i] != '1' && map->raw_map[0][i] != ' '
			&& map->raw_map[0][i] != '\n')
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (map->raw_map[map->height - 1][i] && map->raw_map[map->height
		- 1][i] != '\n')
	{
		if (map->raw_map[map->height - 1][i] != '1' && map->raw_map[map->height
			- 1][i] != ' ')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	is_map_closed(t_map *map, t_header *header, int i)
{
	if (is_raws_closed(map, i) == 1 || is_columns_closed(map, i) == 1)
		error_exit_all("Map is not closed!", header, map);
}
