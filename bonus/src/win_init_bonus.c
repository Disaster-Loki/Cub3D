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

#include "../inc/cub3d_bonus.h"

//g->height = matrix_len(g->sett->map) * g->img.width + 2;
//g->width = max_strlen(g->sett->map) * g->img.height + 2;
void	init_vars(t_game *g, t_sett *sett)
{
	g->flag = 0;
	g->frame = 0;
	g->doors.x = 0;
	g->doors.y = 0;
	g->sett = sett;
	g->name = "CUB3D";
	g->img.ptr = NULL;
	g->mlx = mlx_init();
	valid_img(g);
	g->spt.state = 0;
	g->spt.frame = 0;
	g->spt.offset_y = 0;
	g->pos = pos(g->sett->map);
	g->pos = (t_point_d){g->pos.x + 0.5, g->pos.y + 0.5};
	g->dr_count = found_x(g->sett->map);
	g->door = door_coordinates(g, g->sett->map);
	g->cht = g->sett->map[(int)g->pos.y][(int)g->pos.x];
	mlx_get_screen_size(g->mlx, &g->width, &g->height);
}

void	win_init(char **args)
{
	t_game	g;
	t_sett	sett;

	sett = parsing(args[1]);
	init_vars(&g, &sett);
	player_dir_plane(&g.ray, g.cht);
	g.win = mlx_new_window(g.mlx, g.width, g.height, g.name);
	create_image(&g, &g.img);
	mlx_loop_hook(g.mlx, render_window, &g);
	mlx_hook(g.win, 02, 1L << 0, keypress, &g);
	mlx_mouse_hook(g.win, mouse_hook, &g);
	mlx_hook(g.win, 6, 1L << 6, mouse_move, &g);
	mlx_hook(g.win, 17, 0, close_game, &g);
	mlx_loop(g.mlx);
}
