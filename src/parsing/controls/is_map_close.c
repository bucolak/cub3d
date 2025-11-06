/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:49:24 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/06 15:25:43 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	is_columns_closed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		if (map->raw_map[i][0] != '1' && map->raw_map[i][0] != ' ')
			return (1);
		j = 0;
		while (map->raw_map[i][j])
			j++;
		if (j > 0 && map->raw_map[i][j - 1] != '1' && map->raw_map[i][j
			- 1] != ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	is_raws_closed(t_map *map)
{
	int	i;

	i = 0;
	while (map->raw_map[0][i])
	{
		if (map->raw_map[0][i] != '1' && map->raw_map[0][i] != ' ')
			return (1);
		i++;
	}
	i = 0;
	while (map->raw_map[map->height - 1][i])
	{
		if (map->raw_map[map->height - 1][i] != '1' && map->raw_map[map->height
			- 1][i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	is_map_closed(t_map *map, t_header *header)
{
	if (is_raws_closed(map) == 1 || is_columns_closed(map) == 1)
		error_exit_all("Map is not closed!", header, map);
}
