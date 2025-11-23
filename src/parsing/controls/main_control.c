/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:56:38 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/23 19:47:54 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	is_chars_valid(t_map *map, t_header *header)
// {
// 	int	i;
// 	int	j;
// 	int	flag;

// 	flag = 0;
// 	i = -1;
// 	while (map->raw_map[++i])
// 	{
// 		j = -1;
// 		while (map->raw_map[i][++j])
// 		{
// 			if (map->raw_map[i][j] == '0' || map->raw_map[i][j] == '1'
// 				|| map->raw_map[i][j] == 'N' || map->raw_map[i][j] == 'S'
// 				|| map->raw_map[i][j] == 'E' || map->raw_map[i][j] == 'W'
// 				|| map->raw_map[i][j] == ' ' || map->raw_map[i][j] == '\n')
// 				// getnextline newline'ları alıyo diye hatırlıyorum o yüzden ekledim başka yerlere de eklenmesi gerekiyo olabilir
// 				flag = 1;
// 			else
// 				flag = 0;
// 		}
// 	}
// 	if (flag == 0)
// 		error_exit_all("Invalid Chars in MAP!!", header, map);
// }

static int	are_we_on_map(t_map *init_map)
{
	int	i;

	i = 0;
	while (init_map->raw_map[i])
	{
		if (is_map_started(init_map->raw_map[i]) == 1)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

// static void	header_control(t_map *map, t_header *header)
// {
// 	if (header->c_c != 1 || header->f_c != 1 || header->no_path_c != 1
// 		|| header->so_path_c != 1 || header->ea_path_c != 1
// 		|| header->we_path_c != 1)
// 	{
// 		error_exit_all("Header error!", header, map);
// 	}
// 	is_xpm_valid(map, header);
// }

void	is_player_duplicate(t_map *map, t_header *header)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = -1;
	while (map->raw_map[++i])
	{
		j = 0;
		while (map->raw_map[i][j])
		{
			if (map->raw_map[i][j] == 'S' || map->raw_map[i][j] == 'N'
				|| map->raw_map[i][j] == 'E' || map->raw_map[i][j] == 'W')
				player_count++;
			j++;
		}
	}
	if (player_count != 1)
		error_exit_all("Player count error!", header, map);
}

void	control_map(t_map *map, t_header *header)
{
	// is_empty_line(map, header);
	is_xpm_valid(map, header);
	if (are_we_on_map(map) != -1)
	{
		is_chars_valid(map, header);
		is_map_closed(map, header, are_we_on_map(map));
		is_player_duplicate(map, header);
		is_valid_map(map, header);
	}
}
