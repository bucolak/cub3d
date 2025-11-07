/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:22:49 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/08 00:25:33 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

char	*ft_path_maker(char *line, t_header *init, t_map *map, int type)
{
	char	*ptr;
	char	*start;
	char	*end;
	char	*path;
	char *result;
	(void)map;
	(void)init;

	ptr = line;
	while (ft_isspace(*ptr))
		ptr++;
	ptr += 2;
	while (ft_isspace(*ptr))
		ptr++;
	if (type == F || type == C)
	{
		result = malloc((sizeof(char))*(ft_strlen(ptr) + 1));
		ft_strlcpy(result, ptr,ft_strlen(ptr) + 1);
		return (result);
	}
	start = ptr;
	end = start;
	while (*end && !ft_isspace(*end) && *end != '\n')
		end++;
	while (ft_isspace(*end))
		end++;
	path = ft_substr(start, 0, end - start);
	return (path);
}

int	identifier_check(t_header *init, char *line)
{
	char	*ptr;
	int type;
	
	ptr = line;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	if (!ft_strncmp(ptr, "NO", 2) && ft_isspace(ptr[2]))
	{
		// printf("burda var mısın7?\n");
		init->no_path_c++;
		type = NO;
	}
	else if (!ft_strncmp(ptr, "SO", 2) && ft_isspace(ptr[2]))
	{
		// printf("burda var mısın6?\n");
		init->so_path_c++;
		type = SO;
	}
	else if (!ft_strncmp(ptr, "WE", 2) && ft_isspace(ptr[2]))
	{
		// printf("burda var mısın5?\n");
		init->we_path_c++;
		type = WE;
	}
	else if (!ft_strncmp(ptr, "EA", 2) && ft_isspace(ptr[2]))
	{
		// printf("burda var mısın4?\n");
		init->ea_path_c++;		
		type = EA;
	}
	else if (!ft_strncmp(ptr, "F", 1) && ft_isspace(ptr[1]))
	{
		// printf("burda var mısın3?\n");
		init->f_c++;
		type = F;
	}
	else if (!ft_strncmp(ptr, "C", 1) && ft_isspace(ptr[1]))
	{
		// printf("burda var mısın2?\n");
		init->c_c++;
		type = C;
	}
	else
		type = ERROR;
	return type;
}

void	identifier_load(t_header *init, t_map *map, char *line, int type)
{
	if (type == NO)
		init->no_path = ft_path_maker(line, init, map, type);
	else if (type == SO)
		init->so_path = ft_path_maker(line, init, map, type);
	else if (type == WE)
		init->we_path = ft_path_maker(line, init, map, type);
	else if (type == EA)
		init->ea_path = ft_path_maker(line, init, map, type);
	else if (type == F || type == C)
	{
		// printf("girdimi - Type: %d\n", type); 
		f_c_load(init, map, ft_path_maker(line, init, map, type), type);
	}
}

void	info(t_map *map)
{
	int	i;
	int	j;
	int	max;

	i = -1;
	while (map->raw_map[++i])
	{
		map->height++;
		j = 0;
		while (map->raw_map[i][j] && map->raw_map[i][j] != '\n')
			j++;
		max = j;
		if (max > map->width)
			map->width = max;
		j = -1;
		while (map->raw_map[i][++j])
		{
			if (map->raw_map[i][j] == 'N')
				map->orientation = N;
			if (map->raw_map[i][j] == 'S')
				map->orientation = S;
			if (map->raw_map[i][j] == 'W')
				map->orientation = W;
			if (map->raw_map[i][j] == 'E')
				map->orientation = E;
		}
	}
}

void	find_starting_coordinates(t_map *map) // playerın başlangıç kordinatı için
{
	int	i;
	int	j;

	i = -1;
	while (map->raw_map[++i])
	{
		j = -1;
		while (map->raw_map[i][++j])
		{
			if (map->raw_map[i][j] == 'N' || map->raw_map[i][j] == 'S'
				|| map->raw_map[i][j] == 'W' || map->raw_map[i][j] == 'E')
			{
				map->player_x = j; // Satır numarası (yukarıdan aşağıya)  Y
				map->player_y = i; // Sütun numarası (soldan sağa)	X
			}
		}
	}
}
