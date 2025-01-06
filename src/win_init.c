/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:39:50 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/06 13:39:54 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_vars(t_game *g, char **args)
{
	g->mlx = mlx_init();
	g->g_name = "CUB3D";
	game->pos.y = ft_len_line(game->map) * 32;
	game->pos.x = (int)ft_strlen(*(game->map)) * 32;
}

void	get_img(t_game *game, char *mlx, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	img->no = mlx_xpm_file_to_image(mlx, "./assets/NO.xpm", &x, &y);
	img->so = mlx_xpm_file_to_image(mlx, "./assets/SO.xpm", &x, &y);
	img->we = mlx_xpm_file_to_image(mlx, "./assets/WE.xpm", &x, &y);
	img->ea = mlx_xpm_file_to_image(mlx, "./assets/EA.xpm", &x, &y);
}

void	print_image(t_game *g, char c, int w, int h)
{
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.no, w, h);
	if (c == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->img.so, w, h);
}

void	print_window(t_game *g)
{
	int		i;
	int		j;

	i = -1;
	g->img.wid = 0;
	g->img.hei = 0;
	while (g->map[++i])
	{
		j = -1;
		g->img.wid = 0;
		while (g->map[i][++j])
		{	
			print_image(g, g->map[i][j], g->img.wid, g->img.hei);
			g->img.wid += 32;
		}
		g->img.hei += 32;
	}
}

int	keypress(int key, t_game *game)
{
	//game->pos = begin_position(game->map, 'P');
	if (key == ESC)
		close_game(game);
	return (1);
}

void	win_init(char **args)
{
	t_game	game;

	init_vars(&game, args);
	get_img(&game, game.mlx, &game.img);
	game.win = mlx_new_window(game.mlx, game.pos.x, game.pos.y, game.g_name);
	mlx_hook(game.win, 02, 1L << 0, keypress, &game);
	//mlx_hook(game.win, 17, 0, close_game, &game);
	print_window(&game);
	mlx_loop(game.mlx);
}
