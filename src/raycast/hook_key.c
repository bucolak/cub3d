/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:49:17 by buket             #+#    #+#             */
/*   Updated: 2025/11/12 21:55:37 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_key_hook(int keycode, t_keys *key)
{
    if(keycode == KEY_A)
        key->a = 1;
    if(keycode == KEY_D)
        key->d = 1;
    if(keycode == KEY_W)
        key->w = 1;
    if(keycode == KEY_S)
        key->s = 1;
    if(keycode == KEY_RIGHT_ARROW)
        key->right_arrow = 1;
    if(keycode == KEY_LEFT_ARROW)
        key->left_arrow = 1;
    //if(keycode == KEY_ESC)
        // exit fonksiyonu gelir buraya
}

void ft_key_release(int keycode, t_keys *key)
{
    if(keycode == KEY_A)
        key->a = 0;
    if(keycode == KEY_D)
        key->d = 0;
    if(keycode == KEY_W)
        key->w = 0;
    if(keycode == KEY_S)
        key->s = 0;
    if(keycode == KEY_RIGHT_ARROW)
        key->right_arrow = 0;
    if(keycode == KEY_LEFT_ARROW)
        key->left_arrow = 0;
    //if(keycode == KEY_ESC)
        // exit fonksiyonu gelir buraya
}

void ft_handle_keys(t_keys *key, t_player *player, t_map *map)
{
    if(key->right_arrow == 1)
        ft_rotate_right_move(player, key);
    if(key->left_arrow == 1)
        ft_rotate_left_move(player, key);
    if(key->w == 1)
        ft_move_forward(player, map);
    if(key->s == 1)
        ft_move_backward(player, map);
    if(key->d == 1)
        ft_move_right(player, map);
    if(key->a == 1)
        ft_move_left(player, map);
}