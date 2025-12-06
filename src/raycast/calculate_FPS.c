/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_FPS.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:47:50 by buket             #+#    #+#             */
/*   Updated: 2025/12/06 17:49:38 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long long	get_time_ms(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	ft_calc_FPS(t_player *player)
{
	double	oldTime;
	double	frame_time;

	oldTime = player->time;
	player->time = get_time_ms();
	frame_time = (player->time - oldTime) / 1000.0;
	player->move_speed = frame_time * MOVE_SPEED; // Her frame'de o frame için hareket miktarı hesaplanıyor burda
	player->rot_speed = frame_time * ROT_SPEED;
}
