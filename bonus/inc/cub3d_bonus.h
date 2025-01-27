/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:47:53 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/25 09:55:21 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "file_bonus.h"
# include "../../libft/inc/libft.h"
# include "../../minilibx-linux/mlx.h"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307
# define S_LEFT 65363
# define S_RIGHT 65361
# define EPSILON 0.1
# define SPACE 32

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

typedef struct s_door
{
	int		open;
	int		new_x;
	int		new_y;
	long	is_open;
	long	is_closed;
}	t_door;

typedef struct s_img
{
	int		bpp;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		endian;
	int		line_length;
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
	int			tex_x;
	int			tex_y;
	int			hit;
	int			side;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	long		time;
	double		wall_x;
	int			tex_id;
	long		old_time;
	int			draw_end;
	double		camera_x;
	double		rot_speed;
	double		ray_dir_x;
	double		ray_dir_y;
	int			draw_start;
	double		move_speed;
	double		frame_time;
	double		side_dist_x;
	double		side_dist_y;
	int			line_height;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
}	t_raycast;

typedef struct s_game
{
	t_img		img;
	t_point_d	pos;
	char		cht;
	t_raycast	ray;
	void		*win;
	void		*mlx;
	char		flag;
	t_door		door;
	char		**map;
	char		*name;
	t_sett		*sett;
	int			width;
	int			height;
	int			**textr;
}	t_game;

// close_game.c
void		free_sett(t_sett *sett);
int			close_game(t_game *game);
void		close_img(void *mlx, t_img *img);

// error.c
void		error(char *msg);
void		error_str(char *msg, char *str);

// get_file.c
char		*read_file(int fd);
char		**get_file(char *str);

// utils.cs
void		free_max(char **max);
int			matrix_len(char **max);
int			max_strlen(char **mtx);
void		val_img_path(t_game *game, t_img *img);

// win_init.c
void		win_init(char **args);
void		init_vars(t_game *g, t_sett *sett);

// main.c
void		print_matrix(char **mt);

// Parsing
t_sett		parsing(char *str);
char		**get_map(char **max);
char		*get_value(char **max, char *str);
char		*get_value2(char **max, char *str);

// pos.c
t_point_d	pos(char **map);
int			character(char c);

// draw_window.c
void		clear_window(t_game *g);
void		draw_background(t_game *g);
void		create_image(t_game *g, t_img *img);
void		draw_pixel(t_img *img, int x, int y, int color);

// init_textures.c
void		get_img(t_game *g, t_img *img);
void		init_textures(t_game *g, t_img *img);

//ray_cast
int			render_window(t_game *g);
void		set_tex_wall_x(t_raycast *ray);
void		raycasting(t_game *g, t_raycast *ray);

//ray_dda.c
void		check_hit(t_game *g, t_raycast *ray);
void		set_steps_and_sidedist(t_raycast *ray);

// r_utils.c
long		current_time(void);
t_point_d	create_point(double x, double y);
void		player_dir_plane(t_raycast *ray, char c);

// ray_draw.c
int			get_texture_id(t_raycast *ray);
void		draw_textr(t_game *g, t_raycast *ray, int x);

// ray_vars.c
void		update_frame_time(t_raycast *ray);
void		cal_perp_wall_dist(t_raycast *ray);
void		set_draw_limits(t_game *g, t_raycast *ray);
void		init_ray(t_game *g, t_raycast *ray, int x);

// move_player.c
void		move_up(t_game *g);
void		move_left(t_game *g);
void		move_down(t_game *g);
void		move_right(t_game *g);

// keyboard.c
int			keypress(int key, t_game *game);
int			valid_move(t_game *g, int new_x, int new_y);
void		rotate_view(t_game *g, t_raycast *ray, double speed);

// mini_map_bonus.c
void		mini_map(t_game *g);
void		draw_square(t_img *img, int x, int y, int color);
//void		draw_player(t_img *img, int player_x, int player_y);

// mouse_press_bonus.c
int mouse_init(int x, int y, t_game *g);
int mouse_move(int x, int y, t_game *g);

// door_bonus.c
void	close_door(t_game *g);
void	open_door(t_game *g);
int		valid_move_door(t_game *g, int new_x, int new_y);


#endif
