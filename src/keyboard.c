/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:35:24 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 15:35:27 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	alter_position(t_game *g, t_point pos, int y, int x)
{
	char	move;

	if (pos.y + y > g->pos.y || pos.x + x > g->pos.x)
		return ;
	move = g->sett->map[pos.y + y][pos.x + x];
	if (move != '1')
	{
		g->sett->map[pos.y][pos.x] = '0';
		g->sett->map[pos.y + y][pos.x + x] = g->cht;
		g->ply.y = pos.y + y;
		g->ply.x = pos.x + x;
		render_window(g);
	}
}

int	keypress(int key, t_game *g)
{
	if (key == 'w' || key == 65362)
		alter_position(g, g->ply, -1, 0);
	if (key == 's' || key == 65364)
		alter_position(g, g->ply, 1, 0);
	if (key == 'd' || key == 65363)
		alter_position(g, g->ply, 0, 1);
	if (key == 'a' || key == 65361)
		alter_position(g, g->ply, 0, -1);
	if (key == ESC)
		close_game(g);
	return (1);
}