/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:22:49 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/05 18:36:15 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	identifier_check(t_header *init, char *line)
{
	char	*ptr;

	ptr = line;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	if (!ft_strncmp(ptr, "NO", 2) && ft_isspace(ptr[2]))
		init->type = NO;
	else if (!ft_strncmp(ptr, "SO", 2) && ft_isspace(ptr[2]))
		init->type = SO;
	else if (!ft_strncmp(ptr, "WE", 2) && ft_isspace(ptr[2]))
		init->type = WE;
	else if (!ft_strncmp(ptr, "EA", 2) && ft_isspace(ptr[2]))
		init->type = EA;
	else if (!ft_strncmp(ptr, "F", 1) && ft_isspace(ptr[1]))
		init->type = F;
	else if (!ft_strncmp(ptr, "C", 1) && ft_isspace(ptr[1]))
		init->type = C;
	else
		init->type = ERROR;
}

void	identifier_load(t_header *init, t_map *map, char *line)
{
	if (init->type == NO)
		init->no_path = ft_path_maker(line, init);
	else if (init->type == SO)
		init->so_path = ft_path_maker(line, init);
	else if (init->type == WE)
		init->we_path = ft_path_maker(line, init);
	else if (init->type == EA)
		init->ea_path = ft_path_maker(line, init);
	else if (init->type == F || init->type == C)
		f_c_load(init, map, ft_path_maker(line, init));
}
