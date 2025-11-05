/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 03:12:48 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/05 18:29:57 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char	**make_copy(t_map *map, t_header *header)
// {
// 	char	**cpy_map;
// 	int		x;
// 	int		y;

// 	y = 0;
// 	cpy_map = (char **)malloc(sizeof(char *) * (map->height + 1)); // (map->line_number + 1) line_number olmadığı için height ile değiştirdim
// 	if (!cpy_map)
// 		error_exit_all("Memory allocation failed", header, map);
// 	while (map->grid[y])
// 	{
// 		x = 0;
// 		cpy_map[y] = (char *)malloc(sizeof(char) * (map->width + 1)); // map->column_number -> width ile değiştirildi structta o değeri tutan değişken width olduğu için
// 		if (!(cpy_map[y]))
// 		{
// 			while(--y > 0)
// 				free(cpy_map[y]);
// 			free(cpy_map);
// 			error_exit_all("Memory allocation failed", header, map);
// 		}
// 		while (map->grid[y][x]) // map->map[y][x] map değişkeni yok o yzüden grid eklemeyi düşündüm ama raw_map de olabilir
// 		{
// 			cpy_map[y][x] = map->grid[y][x];
// 			x++;
// 		}
// 		cpy_map[y][x] = '\0';
// 		y++;
// 	}
// 	cpy_map[y] = NULL;
// 	return (cpy_map);
// }

// void	copy_mapcontrol_player(t_map *map, char **cpy_map)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	flood_fill_player(cpy_map, map);
// 	while (cpy_map[y])
// 	{
// 		x = 0;
// 		while (cpy_map[y][x])
// 		{
// 			if (cpy_map[y][x] == 'C')
// 			{
// 				free_cpymap(cpy_map);
// 				ft_error(map, 7);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	copy_mapcontrol_exit(t_map *map, char **cpy_map2)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	flood_fill_for_exit(cpy_map2, map);
// 	while (cpy_map2[y])
// 	{
// 		x = 0;
// 		while (cpy_map2[y][x])
// 		{
// 			if (cpy_map2[y][x] == 'C')
// 			{
// 				free_cpymap(cpy_map2);
// 				ft_error(map, 7);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }
