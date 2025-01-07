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
	(void)args;
	g->mlx = mlx_init();
	g->name = "CUB3D";
	g->pos.y = matrix_len(g->map) * 32;
	g->pos.x = max_strlen(g->map) * 32;
}

void	get_img(t_game *g, t_img *img, int x, int y)
{
	img->no = mlx_xpm_file_to_image(g->mlx, "./assets/NO.xpm", &x, &y);
	img->so = mlx_xpm_file_to_image(g->mlx, "./assets/SO.xpm", &x, &y);
	img->we = mlx_xpm_file_to_image(g->mlx, "./assets/WE.xpm", &x, &y);
	img->ea = mlx_xpm_file_to_image(g->mlx, "./assets/EA.xpm", &x, &y);
}

int	keypress(int key, t_game *game)
{
	if (key == ESC)
		close_game(game);
	return (1);
}

void	win_init(char **args)
{
	t_game	g;

	g.map = malloc(sizeof(char *) * 5);
	g.map[0] = ft_strdup("1111111111");
	g.map[1] = ft_strdup("1011001110");
	g.map[2] = ft_strdup("1000001000");
	g.map[3] = ft_strdup("100N001110");
	g.map[4] = ft_strdup("1111111111");
	g.map[5] = NULL;
	init_vars(&g, args);
	get_img(&g, &g.img, 0, 0);
	g.win = mlx_new_window(g.mlx, g.pos.x, g.pos.y, g.name);
	mlx_hook(g.win, 02, 1L << 0, keypress, &g);
	//mlx_hook(game.win, 17, 0, close_game, &game);
	//print_window(&g);
	mlx_loop(g.mlx);
}