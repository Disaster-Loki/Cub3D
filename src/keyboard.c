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

void	rotate_view(t_game *g, t_raycast *ray, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	g->flag = 1;
	old_dir_x = ray->dir.x;
	ray->dir.y = old_dir_x * sin(speed) + ray->dir.y * cos(speed);
	ray->dir.x = ray->dir.x * cos(speed) - ray->dir.y * sin(speed);
	old_plane_x = ray->plane.x;
	ray->plane.y = old_plane_x * sin(speed) + ray->plane.y * cos(speed);
	ray->plane.x = ray->plane.x * cos(speed) - ray->plane.y * sin(speed);
	render_window(g);
}

int	valid_move(t_game *g, double y, double x)
{
	if (g->sett->map[(int)y][(int)x] == '1')
		return (0);
	return (1);
}

void	move_player(int direc, t_game *g)
{
	double	new_x;
	double	new_y;

	new_x = g->pos.x;
	new_y = g->pos.y;
	if (direc == UP)
	{
		new_x = g->pos.x + g->ray.dir.x * g->ray.move_speed;
		new_y = g->pos.y + g->ray.dir.y * g->ray.move_speed;
	}
	else if (direc == DOWN)
	{
		new_x = g->pos.x - g->ray.dir.x * g->ray.move_speed;
		new_y = g->pos.y - g->ray.dir.y * g->ray.move_speed;
	}
	if (valid_move(g, g->pos.y, new_x))
		g->pos.x = new_x;
	if (valid_move(g, new_y, g->pos.x))
		g->pos.y = new_y;
	render_window(g);
}

void	move_player_horizontal(t_game *g, int direc)
{
	double	new_x;
	double	new_y;

	new_x = g->pos.x;
	new_y = g->pos.y;
	if (direc == RIGHT)
	{
		new_x -= g->ray.dir.y * g->ray.move_speed;
		new_y -= -g->ray.dir.x * g->ray.move_speed;
	}
	else if (direc == LEFT)
	{s
		new_x += g->ray.dir.y * g->ray.move_speed;
		new_y += -g->ray.dir.x * g->ray.move_speed;
	}
	if (valid_move(g, g->pos.y, new_x))
		g->pos.x = new_x;
	if (valid_move(g, new_y, g->pos.x))
		g->pos.y = new_y;
	render_window(g);
}

int	keypress(int key, t_game *g)
{
	if (key == UP || key == DOWN)
		move_player(key, g);
	if (key == LEFT || key == RIGHT)
		move_player_horizontal(g, key);
	if (key == S_RIGHT)
		rotate_view(g, &g->ray, -g->ray.rot_speed);
	if (key == S_LEFT)
		rotate_view(g, &g->ray, g->ray.rot_speed);
	if (key == ESC)
		close_game(g);
	return (1);
}
