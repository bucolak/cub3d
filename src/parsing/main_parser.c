/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:15:14 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/06 18:09:39 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	main_parser(char *header_map, t_map *init, t_header *header)
{
	// int fd;
	// fd = open(header_map, O_RDONLY); 
	map_and_header_parse(header_map, header, init); // burda fd'yi gönderince header_parse içinde raw_map'e malloc ile yer açabilmek için 
	// satır sayısını sayarken fd ilerliyo ve bu sefer içine atma işini yapamıyoruz. 
	// Bu yüzden şimdilik fd yerine file_path gönderip header_parse fonksiyonunda 2 kere açıcam fd'yi
	info(init); // width ve height burda atandı
	find_starting_coordinates(init);
	control_map(init, header); 
	
}