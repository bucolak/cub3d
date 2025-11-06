/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:28:54 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/06 18:03:57 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "limits.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	number;

	number = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	if (number * sign > 255 || number * sign < 0 || nptr[i] != '\0')
		return (-1);
	return (number * sign);
}

// void	*ft_grid_maker(size_t count, size_t size, t_map *init_map)
// {
// 	void			*x;
// 	unsigned char	*str;
// 	size_t			i; // initialize edilecek

// 	x = malloc(count * size);
// 	if (x == NULL)
// 		error_map_exit("Malloc Error,", init_map);
// 	str = (unsigned char *)x;
// 	while (i < (count * size))
// 	{
// 		str[i] == ' ';
// 		i++;
// 	}
// 	return (str);
// }
