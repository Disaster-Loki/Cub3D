/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:39:50 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 12:44:17 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_img(t_game *g, t_img *img, int x, int y)
{
	img->no = mlx_xpm_file_to_image(g->mlx, g->sett->no, &x, &y);
	img->so = mlx_xpm_file_to_image(g->mlx, g->sett->so, &x, &y);
	img->we = mlx_xpm_file_to_image(g->mlx, g->sett->we, &x, &y);
	img->ea = mlx_xpm_file_to_image(g->mlx, g->sett->ea, &x, &y);
	img->width = x;
	img->height = y;
}

void	init_vars(t_game *g, t_sett *sett)
{
	g->flag = 0;
	g->sett = sett;
	g->name = "CUB3D";
	g->mlx = mlx_init();
	get_img(g, &g->img, 0, 0);
	g->pos = pos(g->sett->map);
	g->cht = g->sett->map[(int)g->pos.y][(int)g->pos.x];
	//g->height = matrix_len(g->sett->map) * g->img.width + 2;
	//g->width = max_strlen(g->sett->map) * g->img.height + 2;
	mlx_get_screen_size(g->mlx, &g->width, &g->height);
}

void	win_init(char **args)
{
	t_game	g;
	t_sett	sett;

	sett = parsing(args[1]);
	init_vars(&g, &sett);
	g.win = mlx_new_window(g.mlx, g.width, g.height, g.name);
	render_window(&g);
	mlx_hook(g.win, 02, 1L << 0, keypress, &g);
	mlx_hook(g.win, 17, 0, close_game, &g);
	mlx_loop(g.mlx);
}
