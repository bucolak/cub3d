/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 02:55:45 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/12 16:50:26 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_maker(t_player *player, int x, int screen_width)
{
	double	cameraX;

	cameraX = 2 * x / (double)screen_width - 1; // en sol -1 orta 0 en sağ + 1
	player->rayDirX = player->dirX + player->planeX * cameraX;
	player->rayDirY = player->dirY + player->planeY * cameraX;
}

void	ft_dda(t_player *player, t_map *map)
{
	int		stepX;
	int		stepY;
	int		mapX;
	int		mapY;
	double	posX;
	double	posY;

	posX = player->x;
	posY = player->y;
	mapX = (int)posX;
	mapY = (int)posY;
	player->sideDistX = 0;
	player->sideDistY = 0;
	player->wall_hit = 0;
	player->deltaDistX = fabs(1 / player->rayDirX);
	player->deltaDistY = fabs(1 / player->rayDirY);
	if (player->rayDirX < 0)
	{
		stepX = -1;
		player->sideDistX = (posX - mapX) * player->deltaDistX;
	}
	else
	{
		stepX = 1;
		player->sideDistX = (mapX + 1.0 - posX) * player->deltaDistX;
	}
	if (player->rayDirY < 0)
	{
		stepY = -1;
		player->sideDistY = (posY - mapY) * player->deltaDistY;
	}
	else
	{
		stepY = 1;
		player->sideDistY = (mapY + 1.0 - posY) * player->deltaDistY;
	}
	while (player->wall_hit)
	{
		if (player->deltaDistX < player->deltaDistY)
		{
			player->sideDistX += player->deltaDistX;
			mapX += stepX;
			player->side = 0;
		}
		else
		{
			player->sideDistY += player->deltaDistY;
			mapY += stepY;
			player->side = 1;
		}
		if (map->grid[(int)player->sideDistY][(int)player->sideDistX] == '1')
			player->wall_hit = 1;
	}
}
