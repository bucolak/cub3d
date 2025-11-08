/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:06:57 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/08 12:29:26 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	f_c_load_helper(char *ptr, t_header *init, t_map *map, char **temp)
{
	char	*trim;
	int		val;

	trim = NULL;
	if (ptr)
		trim = ft_strtrim(ptr, " \t\n");
	if (!trim || !*trim)
	{
		free(trim);
		free_2d_array(temp);
		error_exit_all("Empty RGB value", init, map);
	}
	val = ft_atol(trim);
	free(trim);
	if (val < 0 || val > 255)
	{
		free_2d_array(temp);
		error_exit_all("RGB value must be between 0-255", init, map);
	}
	return (val);
}

void	f_c_load(t_header *init, t_map *map, char *ptr, int type)
{
	int		i;
	char	**temp;
	int		val;

	i = 0;
	temp = ft_split(ptr, ',');
	while (i < 3)
	{
		val = f_c_load_helper(temp[i], init, map, temp);
		if (type == F)
			init->f_rgb[i] = val;
		else
			init->c_rgb[i] = val;
		i++;
	}
	free_2d_array(temp);
}
