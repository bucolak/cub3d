/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:15:14 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/08 12:29:21 by bucolak          ###   ########.fr       */
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

void	file_name_control(char *header_map, t_map *map, t_header *header)
{
	int	i;
	int	end;

	i = 0;
	while (header_map[i])
		i++;
	end = i - 1;
	if ((end - 4) > 0 && header_map[end] == 'b' && header_map[end - 1] == 'u'
		&& header_map[end - 2] == 'c' && header_map[end - 3] == '.')
		return ;
	error_exit_all("Wrong file name!", header, map);
}

void	main_parser(char *header_map, t_map *init, t_header *header)
{
	file_name_control(header_map, init, header);
	read_entire_file(header_map, init, header);
	// print_raw_map(init);
	info(init); // width ve height burda atandı
	find_starting_coordinates(init);
	control_map(init, header);
}
