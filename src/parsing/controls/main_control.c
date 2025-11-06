/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:56:38 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/06 18:10:28 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	is_chars_valid(t_map *map, t_header *header)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = -1;
	while (map->raw_map[++i])
	{
		j = -1;
		while (map->raw_map[i][++j])
		{
			if (map->raw_map[i][j] == '0' || map->raw_map[i][j] == '1'
				|| map->raw_map[i][j] == 'N' || map->raw_map[i][j] == 'S'
				|| map->raw_map[i][j] == 'E' || map->raw_map[i][j] == 'W'
				|| map->raw_map[i][j] == ' ')
				flag = 1;
			else
				flag = 0;
		}
	}
	if (flag == 0)
		error_exit_all("Invalid Chars in MAP!!", header, map);
}

static void	is_empty_line(t_map *map, t_header *header)
{
	int	i;
	int	len;
	int	j;

	j = -1;
	i = -1;
	while (map->raw_map[++i])
	{
		len = ft_strlen(map->raw_map[i]);
		if (len == 0)
			error_exit_all("There is an empty line in the MAP!!", header, map);
		while (map->raw_map[i][++j])
			;
		if (len == j)
			error_exit_all("There is an empty line in the MAP!!", header, map);
	}
}

void	control_map(t_map *map, t_header *header)
{
	is_chars_valid(map, header);
	is_empty_line(map, header);
	is_map_closed(map, header);
	is_valid_map(map, header);
}