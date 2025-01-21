/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:47:53 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 12:25:21 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"

# define UP 119
# define DOWN 115
# define ESC 65307
# define S_LEFT 65363
# define S_RIGHT 65361
# define EPSILON 0.1

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_point_d
{
	double	x;
	double	y;
}	t_point_d;

typedef struct s_img
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	void	*ptr;
	int		width;
	int		height;
	char    *addr;         
    int     bpp;           
    int     line_length;   
    int     endian;
}	t_img;

typedef struct s_sett
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**map;
	int		c_roof;
	int		c_floor;
}	t_sett;

typedef struct s_raycast
{
	t_point_d	pos;
	t_point_d	dir;
	t_point_d	plane;
	int			hit;
	int 		side;
	int			map_x;
	int			map_y;
	int 		step_x;
	int 		step_y;
	double		rot_speed;
	double		move_speed;
	long		time;
	long		old_time;
	double		frame_time;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			draw_end;
	int			draw_start;
	double		side_dist_x;
	double		side_dist_y;
	int			line_height;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
}	t_raycast;

typedef struct s_game
{
	t_img	img;
	t_point_d	pos;
	int		width;
	int		height;
	t_sett	*sett;
	void	*mlx;
	void	*win;
	char	*name;
	char	**map;
	char	cht;
	t_raycast ray;
	char	flag;
}	t_game;

// Close
int		win_close(t_game *game);
int		close_game(t_game *game);
void	close_img(void *mlx, t_img *img);

// Error
void	error(char *msg);
void	error_str(char *msg, char *str);

// Get_file
char	*read_file(int fd);
char	**get_file(char *str);

// Utils
void	free_max(char **max);
int		matrix_len(char **max);
int		max_strlen(char **mtx);
void	val_img_path(t_game *game, t_img *img);

// Val_file
int		open_file(char *file);

// Win_init
void	win_init(char **args);
void	init_vars(t_game *g, t_sett *sett);
int		keypress(int key, t_game *game);
void	get_img(t_game *g, t_img *img, int x, int y);

// Main
void	print_matrix(char **mt);

// Parsing
t_sett	parsing(char *str);
t_point_d	pos(char **map);
char	**get_map(char **max);
char	*get_value(char **max, char *str);
int		val_charater(char c);
void 	p_direction(t_raycast *ray, char c);
int 	render_window(t_game *g);
int		character(char c);
t_point_d	create_point(double x, double y);
long	current_time(void);
void	player_dir_plane(t_raycast *ray, char c);

// Validate
void	validate_file(char **max, char *str);
// char	*dell_spaces(char *str);
void	validate_elements(char **max);

// treat_map.c.c
void	treat_map(char **max, char *str);
void	map_new_line(char *str, char **max);
void	help_new_line(char *file, int i, char **max);
void	get_map_to_validate(char *file, int i);
void	validate_map(char *str, char **max);

// forbiden_char.c
void	has_player(char **map, char **max);
void	forbiden_char(char **map, char **max);

// player_in_map.c
void	player_in_map(char **map, char **max);
void	only_n(char **map, int i, int j, char **max);
void	only_s(char **map, int i, int j, char **max);
void	only_w(char **map, int i, int j, char **max);
void	only_e(char **map, int i, int j, char **max);

// more_players.c
void	more_players(char **map, char **max);
void	more_n(char **map, int i, int j, char **max);
void	more_s(char **map, int i, int j, char **max);
void	more_w(char **map, int i, int j, char **max);
void	more_e(char **map, int i, int j, char **max);

// many_textures.c
void	many_textures(char **max);
void	west(char **max);
void	east(char **max);
void	south(char **max);
void	north(char **max);

// good_textures.c
void	good_textures(char **max);
void	good_we(char **mat, char *str);
void	good_ea(char **mat, char *str);
void	good_so(char **mat, char *str);
void	good_no(char **mat, char *str);

// textures_path.c
void	textures_path(char **max);
void	path_we(char *path, char **max);
void	path_ea(char *path, char **max);
void	path_so(char *path, char **max);
void	path_no(char *path, char **max);

// textures_extencion.c
void	textures_extencion(char **max);
void	extencion_we(char *str, char **max);
void	extencion_ea(char *str, char **max);
void	extencion_so(char *str, char **max);
void	extencion_no(char *str, char **max);

// many_colors.c
char	**split_color(char *str);
void	many_colors(char **max);
void	one_floor(char **max);
void	one_roof(char **max);

// floor_roof.c
void	floor_roof(char **max);
void	floor_roof_weird_char(char *floor, char *roof, char **max);
void	floor_roof_one_space(char *floor, char *roof);
void	big_nbr_color(char *floor, char *roof);
char	**split_color(char *str);

// sorrounded_by_1.c
void	walls_at_edges(char **map, char **max);
void	inside_map(char **map, char **max);
void	char_by_char(char **map2, char **map, char **max);
void	last_char(char **map, char **max);
int		bigger_line(char **mat);

// help_sorround_by_1.c
void	middle_lines(char **map, char **max);
void	last_line(char **mat, char **max);

#endif
