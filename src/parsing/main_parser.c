/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:15:14 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/23 18:38:51 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_raw_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->raw_map[i])
	{
		printf("%s\n", map->raw_map[i]);
		i++;
	}
}

void	main_parser(char *header, t_header *init, t_map *map)
{
	int	fd;

	fd = open(header, O_RDONLY);
	if (fd == -1)
		error_exit_all("Invalid file name!", init, map);
	header_parse(fd, init, map);
	print_raw_map(map);
	map_parse(map, init);
}
