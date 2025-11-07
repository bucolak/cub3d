/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:46:43 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/08 00:21:14 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_header *init;
	t_map *map;
	
	if (argc != 2)
	{
		ft_putendl_fd("Error: Usage: ./cub3d <map.cub>", 2);
		return (1);
	}
	init = init_header();
	map = init_map();
	main_parser(argv[1], map, init);
	// debug(map, init);
}