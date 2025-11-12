/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:02:28 by buket             #+#    #+#             */
/*   Updated: 2025/11/12 21:50:06 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_rotate_right_move(t_player *player, t_keys *key)
{
    double oldDirX;
    double oldPlaneX;
    double rotSpeed;
    
    oldDirX = player->dirX;
    oldPlaneX = player->planeX;
    rotSpeed = player->rotSpeed;
    player->dirX = player->dirX * cos(-rotSpeed) - player->dirY * sin(-rotSpeed);
    player->dirY = oldDirX * sin(-rotSpeed) + player->dirY * cos(-rotSpeed);
    
    player->planeX = player->planeX * cos(-rotSpeed) - player->planeY * sin(-rotSpeed);
    player->planeY = oldPlaneX * sin(-rotSpeed) + player->planeY * cos(-rotSpeed);
}

void ft_rotate_left_move(t_player *player, t_keys *key)
{
    double oldDirX;
    double oldPlaneX;
    double rotSpeed;
    
    oldDirX = player->dirX;
    oldPlaneX = player->planeX;
    rotSpeed = player->rotSpeed;
    player->dirX = player->dirX * cos(rotSpeed) - player->dirY * sin(rotSpeed);
    player->dirY = oldDirX * sin(rotSpeed) + player->dirY * cos(rotSpeed);
    
    player->planeX = player->planeX * cos(rotSpeed) - player->planeY * sin(rotSpeed);
    player->planeY = oldPlaneX * sin(rotSpeed) + player->planeY * cos(rotSpeed);
}

void ft_move_forward(t_player *player, t_map *map)
{
    if(map->grid[(int)(player->x + player->dirX * player->moveSpeed)][(int)player->y] != '1')
        player->x += player->dirX * player->moveSpeed;
    if(map->grid[(int)player->x][(int)(player->y + player->dirY * player->moveSpeed)] != '1')
        player->y += player->dirY * player->moveSpeed;
}

void ft_move_backward(t_player *player, t_map *map)
{
    if(map->grid[(int)(player->x - player->dirX * player->moveSpeed)][(int)player->y] != '1')
        player->x -= player->dirX * player->moveSpeed;
    if(map->grid[(int)player->x][(int)(player->y - player->dirY * player->moveSpeed)] != '1')
        player->y -= player->dirY * player->moveSpeed;
}

void ft_move_right(t_player *player, t_map *map)
{
    if(map->grid[(int)(player->x + player->planeX * player->moveSpeed)][(int)player->y] != '1')
        player->x += player->planeX * player->moveSpeed;
    if(map->grid[(int)player->x][(int)(player->y + player->planeY * player->moveSpeed)] != '1')
        player->y += player->planeY * player->moveSpeed;
}

void ft_move_left(t_player *player, t_map *map)
{
    if(map->grid[(int)(player->x - player->planeX * player->moveSpeed)][(int)player->y] != '1')
        player->x -= player->planeX * player->moveSpeed;
    if(map->grid[(int)player->x][(int)(player->y - player->planeY * player->moveSpeed)] != '1')
        player->y -= player->planeY * player->moveSpeed;
}