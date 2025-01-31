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

void	move_up(t_game *g)
{
	double	new_x;
	double	new_y;

	new_x = g->ray.pos.x + (g->ray.dir.x * g->ray.move_speed);
	new_y = g->ray.pos.y + (g->ray.dir.y * g->ray.move_speed);
	if (valid_move(g, new_x, new_y))
	{
		g->pos.x = new_x;
		g->pos.y = new_y;
		render_window(g);
	}
}

void	move_down(t_game *g)
{
	double	new_x;
	double	new_y;

	new_x = g->ray.pos.x - (g->ray.dir.x * g->ray.move_speed);
	new_y = g->ray.pos.y - (g->ray.dir.y * g->ray.move_speed);
	if (valid_move(g, new_x, new_y))
	{
		g->pos.x = new_x;
		g->pos.y = new_y;
		render_window(g);
	}
}

void	move_left(t_game *g)
{
	double	new_x;
	double	new_y;

	new_x = g->ray.pos.x - (g->ray.plane.x * g->ray.move_speed);
	new_y = g->ray.pos.y - (g->ray.plane.y * g->ray.move_speed);
	if (valid_move(g, new_x, new_y))
	{
		g->pos.x = new_x;
		g->pos.y = new_y;
		render_window(g);
	}
}

void	move_right(t_game *g)
{
	double	new_x;
	double	new_y;

	new_x = g->ray.pos.x + (g->ray.plane.x * g->ray.move_speed);
	new_y = g->ray.pos.y + (g->ray.plane.y * g->ray.move_speed);
	if (valid_move(g, new_x, new_y))
	{
		g->pos.x = new_x;
		g->pos.y = new_y;
		render_window(g);
	}
}
