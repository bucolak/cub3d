/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:56:38 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/08 00:27:42 by buket            ###   ########.fr       */
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

static int	are_we_on_map(t_map *init_map)
{
	int	i;
	
	i = 0;
	while(init_map->raw_map[i])
	{
		
		if(is_map_started(init_map->raw_map[i]) == 1)
			return i;
		i++;
	}	
	return (0);
}

static void header_control(t_map *map, t_header *header)
{
	// printf("c_c: %d, f_c: %d, no_path_c: %d, so_path_c: %d, ea_path_c: %d, we_path_c: %d\n",
    //        header->c_c, header->f_c, header->no_path_c, 
    //        header->so_path_c, header->ea_path_c, header->we_path_c);
	if(header->c_c != 1 || header->f_c != 1 || header->no_path_c != 1 
		|| header->so_path_c != 1 || header->ea_path_c != 1 || header->we_path_c != 1)
	{
		error_exit_all("Header error!", header, map);
	}
}

void	control_map(t_map *map, t_header *header)
{
	// is_empty_line(map, header);
	header_control(map, header);
	if(are_we_on_map(map) == 1)
	{
		is_chars_valid(map, header);
		is_map_closed(map, header, are_we_on_map(map));
	is_valid_map(map, header);
	}
}