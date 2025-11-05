/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:44:36 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/05 18:36:22 by bucolak          ###   ########.fr       */
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
	int		type;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int f_rgb[3]; // neden pointerlı ? (şuanlık kaldırdım pointerı ama ekleybilirz, kolay derlenmesi için kaldırdım)
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
}			t_map;

// ==================== main_parser.c ====================
void	main_parser(char *header_map, t_map *init, t_header *header);

// ==================== element_parse.c ====================
void	header_parse(char *header_map, t_header *init, t_map *init_map);

// ==================== rgb_parse.c ====================
void	f_c_load(t_header *init, t_map *map, char *ptr);

// ==================== element_identifier.c ====================
void	identifier_check(t_header *init, char *line);
void	identifier_load(t_header *init, t_map *map, char *line);


// ==================== map_parser.c ====================
void		map_parse(t_map *map);

// ==================== exit_1.c ====================
void		error_map_exit(t_map *init_map);
void		error_exit_header(t_header *init);
void		cleanup_all(t_header *header, t_map *map);
void		free_2d_array(char **array);
void		error_exit_all(char *msg, t_header *header, t_map *map);

// ==================== cpymap.c ====================
char		**make_copy(t_map *map, t_header *header);

// ==================== parsing_utils.c ====================
int	ft_isspace(char c);
char	*ft_path_maker(char *line, t_header *init);

// ==================== init.c ====================
t_header	*init_header(void);
t_map	*init_map(void);



int			ft_atol(const char *nptr);

#endif