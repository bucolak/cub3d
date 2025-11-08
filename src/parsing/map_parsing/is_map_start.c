/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:51:42 by buket             #+#    #+#             */
/*   Updated: 2025/11/08 12:29:30 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	is_map_started_helper(char *line, int *i)
{
	if (line[*i] == '1' || line[*i] == '0' || line[*i] == 'N' || line[*i] == 'S'
		|| line[*i] == 'E' || line[*i] == 'W')
	{
		while (line[*i])
		{
			if (line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
			{
				(*i)++;
				continue ;
			}
			if (line[*i] == '1' || line[*i] == '0' || line[*i] == 'N'
				|| line[*i] == 'S' || line[*i] == 'E' || line[*i] == 'W')
			{
				(*i)++;
				continue ;
			}
			return (0);
		}
		return (1);
	}
	else
		return (0);
}

int	is_map_started(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		{
			i++;
			continue ;
		}
		if (is_map_started_helper(line, &i) == 1)
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}
