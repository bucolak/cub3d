/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:24:37 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/26 18:49:16 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_window(t_mlx *mlx, t_map *map, t_header *header)
{
	if (!(mlx->ptr))
		error_exit_all("MLX error!", header, map, mlx);
	mlx->win = mlx_new_window(mlx->ptr, WIN_W, WIN_H, "cub3D");
	if (!mlx->win)
		error_exit_all("MLX error!", header, map, mlx);
	mlx->img.img = mlx_new_image(mlx->ptr, WIN_W, WIN_H);
	if (!mlx->img.img)
		error_exit_all("MLX error!", header, map, mlx);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.line_len, &mlx->img.endian);
	// ft_2d_init(mlx); // for2d
}

int	close_window(t_mlx *mlx)
{
	cleanup_all(mlx->header, mlx->map, mlx);
	exit(0);
}
