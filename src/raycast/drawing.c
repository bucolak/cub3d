/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:54:49 by buket             #+#    #+#             */
/*   Updated: 2025/11/12 19:53:10 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void initialize_player(t_player *player)
{
    player->deltaDistX = 0;
    player->deltaDistY = 0;
    player->dirX = 0;
    player->dirY = 0;
    player->moveSpeed = 0;
    player->planeX = 0;
    player->planeY = 0;
    player->rayDirX = 0;
    player->rayDirY = 0;
    player->rotSpeed = 0;
    player->side = -1;
    player->sideDistX = 0;
    player->sideDistY = 0;
    player->time = 0;
    player->wall_hit = -1;
    player->x = 0;
    player->y = 0;
}

void ft_calc_draw_params(t_player *player)
{
    double perpWallDist;
    int lineHeight;
    
    if(player->side == 0)
        perpWallDist = player->sideDistX-player->deltaDistX;
    else
        perpWallDist = player->sideDistY-player->deltaDistY;
    lineHeight = (int)(WIN_W / perpWallDist);
    player->drawStart = (WIN_H / 2) - (lineHeight / 2);
    if(player->drawStart < 0)
        player->drawStart = 0;
    player->drawEnd = (WIN_H / 2) + (lineHeight / 2);
    if(player->drawEnd >= WIN_H)
        player->drawEnd = WIN_H - 1;
}

long long get_time_ms()
{
    struct timeval tv;
    long long time;

    gettimeofday(&tv, NULL);
    time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return time;
}

void ft_calc_FPS(t_player *player)
{
    double oldTime;
    double frameTime;

    oldTime = player->time;
    player->time = get_time_ms();
    frameTime = (player->time - oldTime) / 1000.0;
    player->moveSpeed = frameTime * 5.0; // bu 5 ve 3 değerleri değişebilir.
    player->rotSpeed = frameTime * 3.0; 
}


