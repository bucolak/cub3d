/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:15:14 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/08 00:21:28 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	print_raw_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->raw_map[i])
	{
		printf("%s", map->raw_map[i]);
		i++;
	}
}

void	main_parser(char *header_map, t_map *init, t_header *header)
{
	read_entire_file(header_map, init, header);
	// print_raw_map(init);
	info(init); // width ve height burda atandı
	find_starting_coordinates(init);
	control_map(init, header); 
}
