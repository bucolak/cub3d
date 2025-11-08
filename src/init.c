/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:29:34 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/08 12:29:06 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_header	*init_header(void)
{
	t_header	*header;

	header = malloc(sizeof(t_header));
	if (!header)
	{
		ft_putendl_fd("Error: Memory allocation failed for header", 2);
		return (NULL);
	}
	header->c_rgb[0] = -1;
	header->c_rgb[1] = -1;
	header->c_rgb[2] = -1;
	header->f_rgb[0] = -1;
	header->f_rgb[1] = -1;
	header->f_rgb[2] = -1;
	header->ea_path = NULL;
	header->no_path = NULL;
	header->so_path = NULL;
	header->we_path = NULL;
	return (header);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_putendl_fd("Error: Memory allocation failed for map", 2);
		return (NULL);
	}
	map->grid = NULL;
	map->height = 0;
	map->orientation = -1;
	map->player_x = -1;
	map->player_y = -1;
	map->raw_map = NULL;
	map->width = 0;
	map->has_map = 0;
	return (map);
}
