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

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"

# define ESC 65307

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}			t_img;

typedef struct s_sett
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**map;
	char	*c_roof;
	char	*c_floor;
}	t_sett;

typedef struct s_game
{
	t_img	img;
	t_point	pos;
	t_sett	*sett;
	void	*mlx;
	void	*win;
	char	*name;
	char	**map;
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

#endif
