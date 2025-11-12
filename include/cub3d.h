/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:44:36 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/12 21:59:53 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h> // for open() read()
# include <math.h>
# include <stdio.h> // for printf
# include <stdlib.h>
# include <unistd.h>
#include <sys/time.h> 

# define WIN_W 1920
# define WIN_H 1080
# define FOV_DEG 66.0
# define M_PI 3.14159265358979323846
# define ROT_SPEED 0.05
# define MOVE_SPEED 0.05

#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_LEFT_ARROW 65361
#  define KEY_RIGHT_ARROW 65363
#  define KEY_ESC 65307

enum		TYPE
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	ERROR,
};

enum		ORIENTATION
{
	N,
	S,
	W,
	E,
};

typedef struct s_header
{
	// int		type;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;

	// duplicate kontrolü için
	int		no_path_c;
	int		so_path_c;
	int		we_path_c;
	int		ea_path_c;
	int		f_c;
	int		c_c;

	int f_rgb[3];
		// neden pointerlı ? (şuanlık kaldırdım pointerı ama ekleybilirz, kolay derlenmesi için kaldırdım)
	int		c_rgb[3];

}			t_header;

typedef struct s_map
{
	char	**raw_map;
	char	**grid;
	int		orientation;
	int		player_x;
	int		player_y;
	int		height;
	int		width;
	int has_map; // normdan dolayı buraya ekledim map var mı diye kontrol ediyo
}			t_map;

typedef struct s_player
{
	double		x;
	double		y;
	double dirX;   // oyuncunun baktığı yön
	double dirY;   // oyuncunun baktığı yön
	double planeX; // oyuncu plane (aslında kendisi gibi bişi)
	double planeY; // oyuncu plane (aslında kendisi gibi bişi)
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	int			wall_hit;
	int			side;  
	
	double	deltaDistX;
	double	deltaDistY;
	double time;
	double moveSpeed;
    double rotSpeed;
	int drawStart;
    int drawEnd;
}				t_player;

typedef struct s_img
{
	void *img;    // MLX image pointer (handle)
	char *addr;   // bellekteki piksel adresi
	int bpp;      // bits per pixel
	int line_len; // bir satırın byte uzunluğu
	int endian;   // sistem endian tipi
}				t_img;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int right_arrow;
	int left_arrow;
}				t_keys;

typedef struct s_mlx
{
	void		*win;
	void		*ptr;
	t_img		img;
	t_map		*map;
	t_header	*header;
	t_keys		keys;

}				t_mlx;

// init.c
t_header	*init_header(void);
t_map		*init_map(void);

// main_parser.c
void		main_parser(char *header_map, t_map *init, t_header *header);

// element_parse.c
void		read_entire_file(char *header_map, t_map *map, t_header *header);

// element_identifier.c
void		info(t_map *map);
void		identifier_load(t_header *init, t_map *map, char *line, int type);
int			identifier_check(t_header *init, char *line);
void		find_starting_coordinates(t_map *map);

// main_control.c
void		control_map(t_map *map, t_header *header);

// is_map_close.c
void		is_map_closed(t_map *map, t_header *header, int i);

// parsing_utils.c
int			ft_isspace(char c);
int			ft_atol(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);

// is_map_start.c
int			is_map_started(char *line);

// exit_1.c
void		free_2d_array(char **array);
void		error_exit_all(char *msg, t_header *header, t_map *map);

// rgb_parse.c
void		f_c_load(t_header *init, t_map *map, char *ptr, int type);

// is_valid_mapp.c
void		is_valid_map(t_map *map, t_header *header);

// xpm_control.c
void		is_xpm_valid(t_map *map, t_header *header);

// movement.c
void ft_rotate_right_move(t_player *player, t_keys *key);
void ft_rotate_left_move(t_player *player, t_keys *key);
void ft_move_forward(t_player *player, t_map *map);
void ft_move_backward(t_player *player, t_map *map);
void ft_move_right(t_player *player, t_map *map);
void ft_move_left(t_player *player, t_map *map);

// draving.c
void initialize_player(t_player *player);
void ft_calc_draw_params(t_player *player);
long long get_time_ms();
void ft_calc_FPS(t_player *player);

#endif